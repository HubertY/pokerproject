const { TCPConnection, CalcServ } = require("./net.js")
const { PreflopTracker, playPreflop } = require("./preflop.js")
const { fs, FACES, SUITS, ALL_CARDS, CARD_ID, ALL_HANDS, HAND_ID, PREFLOP_HANDS, PREFLOP_EQUITY, PREFLOP_HAND_ID, initConstants } = require("./constants.js");
const { sum, scale, normalize, multiply, mask } = require("./util.js");

async function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
}

let calcserv = null;
let pftracker = new PreflopTracker();

//sort ascending
function parseHand(hand) {
    let cards = [hand.slice(0, 2), hand.slice(2, 4)].sort((h1, h2) => CARD_ID[h1] - CARD_ID[h2]);
    return cards[0] + cards[1];
}

//sort descending
function reorderFlop(flop) {
    let cards = [flop.slice(0, 2), flop.slice(2, 4), flop.slice(4, 6)].sort((h1, h2) => CARD_ID[h2] - CARD_ID[h1]);
    return cards[0] + cards[1] + cards[2] + flop.slice(6);
}

//return suit permutation to c d h s order
function permuteSuits(cards) {
    let ret = {};
    let suitsLeft = ["s", "h", "d", "c"];
    for (let i = 0; i < cards.length; i += 2) {
        let suit = cards[i + 1];
        if (ret[suit] === undefined) {
            ret[suit] = suitsLeft.pop();
        }
    }
    for (let suit of SUITS) {
        if (ret[suit] === undefined) {
            ret[suit] = suitsLeft.pop();
        }
    }
    return ret;
}

function applySuitPermutation(cards, permutation) {
    let ret = "";

    //SUPER SPECIAL EDGE CASE :O
    if (cards[0] === cards[2] && cards[5] === cards[1]) {
        cards = cards.slice(0,5) + cards[3] + cards.slice(6);
    }
    
    for (let i = 0; i < cards.length; i += 2) {
        ret += cards[i];
        ret += permutation[cards[i + 1]];
    }
    return reorderFlop(ret);
}

//ex 50/100 -> 0.25 equity needed to call
function equityThreshold(stake, bet) {
    return (bet - stake) / bet / 2;
}

function getPostFlopProbMultiplier(stake, bet, baseeqs, raise = false) {
    let thresh = equityThreshold(stake, bet);
    let q = 5;
    if (raise) {
        thresh = thresh + 0.4 * (1 - stake / bet);
        //console.log(stake, bet, thresh);
        q = 10;
    }
    let ret = baseeqs.map(x => x >= thresh ? q : 1);
    return ret;
}

function cutOff20k(n) {
    return n > 20000 ? 20000 : n;
}

/**
 * @param {string} gameString
 */
async function process(gameString) {
    return new Promise(async (resolve) => {
        let timeout = true;
        // setTimeout(() => {
        //     if (timeout) {
        //         console.log("WARNING: TIMEOUT");
        //         resolve("c");
        //     }
        // }, 6500); //definitely resolves within 6.5 seconds, just call if it times out

        const [_, pos, handNumber, betting, cards] = gameString.split(":");

        const position = parseInt(pos);
        const opposition = position ? 0 : 1;
        const cardsTokens = cards.split("/");
        let handarray = cardsTokens[0].split("|");
        let hand = parseHand(handarray[position]);

        if (handarray[opposition].length) {
            console.log("can see opponent's cards; hand is over");
            timeout = false;
            resolve();
            return;
        }

        const rounds = betting.split("/").map((round) => {
            const roundTokens = round.replace(/[a-z]/g, "$$$&").split("$");
            let ret = [];
            for (let token of roundTokens) {
                if (token.length) {
                    if (token[0] === "c") {
                        ret.push({ type: "c" });
                    }
                    else if (token[0] === "r") {
                        let value = parseInt(token.slice(1));
                        ret.push({ type: "r", value });
                    }
                    else if (token[0] === "f") {
                        ret.push({ type: "f" });
                    }
                }
            }
            return ret;
        });
        const currRound = rounds[rounds.length - 1];

        if (currRound.length && currRound[currRound.length - 1].type === "f") {
            console.log('fold occurred, round is over');
            timeout = false;
            resolve();
        }
        else if (rounds.length === 1 && currRound.length % 2 === position || rounds.length > 1 && currRound.length % 2 !== position) {
            console.log("not my turn");
            timeout = false;
            resolve();
        }
        else if (rounds.length === 1) {
            //PREFLOP
            console.log("taking preflop action");
            timeout = false;
            resolve(playPreflop(hand, rounds[0], position));
        }
        else if (rounds.length > 1) {
            console.log("taking postflop action");
            if (rounds[1].length === 0) {
                pftracker.feed(rounds[0], opposition);
            }
            //POSTFLOP

            let board = reorderFlop(cardsTokens[1]);
            for (let i = 2; i < cardsTokens.length; i++) {
                if (cardsTokens[i].trim().length) {
                    board += cardsTokens[i].trim();
                }
            }

            let permute = permuteSuits(board);
            board = applySuitPermutation(board, permute);
            hand = parseHand(applySuitPermutation(hand, permute));

            let eqs = await calcserv.getVillains(hand, board);
            let baseeqs = await calcserv.getVillains("random", board);


            let p1 = pftracker.query(rounds[0], opposition);
            let p2 = ALL_HANDS.map(x => 1);


            let stake = 50;
            let bet = 100;
            let minraise = 100;
            for (let action of rounds[0]) {
                if (action.type === "c") {
                    stake = bet;
                }
                else if (action.type === "r") {
                    minraise = action.value - bet;
                    stake = bet;
                    bet = action.value;
                }
            }
            for (let i = 1; i < rounds.length; i++) {
                for (let j = 0; j < rounds[i].length; j++) {
                    let action = rounds[i][j];
                    let oppoturn = j % 2 == opposition;
                    if (action.type === "c") {
                        if (oppoturn) {
                            p2 = multiply(p2, getPostFlopProbMultiplier(stake, bet, baseeqs));
                        }
                        stake = bet;
                    }
                    else if (action.type === "r") {
                        if (oppoturn) {
                            p2 = multiply(p2, getPostFlopProbMultiplier(stake, action.value, baseeqs, true));
                        }
                        minraise = action.value - bet;
                        stake = bet;
                        bet = action.value;
                    }
                }
            }

            let action = "c";
            let villaineqdist = multiply(normalize(multiply(mask(eqs), multiply(p1, p2))), eqs);
            let finaleqestimate = 1 - sum(villaineqdist);
            let eqthresh = equityThreshold(stake, bet);
            if (finaleqestimate < eqthresh) {
                if (Math.random() > finaleqestimate / eqthresh) {
                    action = "f";
                }
                else {
                    action = "c";
                }
            }
            else {
                action = "c";
                if (finaleqestimate > 0.8) {
                    if (Math.random() < finaleqestimate) {
                        action = "r" + cutOff20k(Math.floor(bet * 3));
                    }
                }
                if (finaleqestimate > 0.5) {
                    if (Math.random() < finaleqestimate) {
                        action = "r" + cutOff20k(Math.floor(bet * 1.5));
                    }
                }
            }
            if (rounds.length === 2 && action === "c" && Math.random() > 0.9) {
                action = "r" + cutOff20k(bet * 3);
            }
            if (action === "r20000" && bet === 20000) {
                action = "c";
            }
            timeout = false;
            resolve(action);
        }
    });
}



async function main(delay = 1000) {
    await sleep(delay);

    console.log("reading config.json...");
    const config = JSON.parse(fs.read("config.json"));
    if (!config || !config.calcServer || !config.gameServer) {
        throw Error("config.json is invalid");
    }

    console.log("initializing constants");
    initConstants();

    console.log("connecting to calculation server...");
    const calc = new TCPConnection(config.calcServer);
    await calc.connect();

    calcserv = new CalcServ(calc);

    //console.log(await process("MATCHSTATE:1:0:cr200c/cc/cc/r7748:|9hQd/8dAs8s/4h"));

    console.log("connecting to game server...");
    const game = new TCPConnection(config.gameServer);
    await game.connect();


    await game.sendMessage("VERSION:2.0.0\r\n");

    while (true) {
        const msgs = (await game.nextMessage()).trim().split("\n");
        for (let msg of msgs) {
            msg = msg.trim();
            if (msg.length) {
                console.log(`RECEIVED: ${msg}`);
                if (msg[0] !== "#" && msg[0] !== ";") {
                    const response = await process(msg);
                    if (response && response.length) {
                        console.log(`SENDING: ${response}`);
                        game.sendMessage(`${msg}:${response}\r\n`);
                    }
                }
            }
        }
    }
}


main();
