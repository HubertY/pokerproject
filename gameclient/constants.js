const _fs = require("fs");

const FACES = ["A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2"];
const SUITS = ["s", "h", "d", "c"]
const ALL_CARDS = []; //52
const CARD_ID = {};
const ALL_HANDS = []; //1326, sorted naively
const HAND_ID = {};

const PREFLOP_HANDS = []; //169, sorted by preflop equity
const PREFLOP_EQUITY = [];
const PREFLOP_HAND_ID = {}

const fs = {
    dir: "",
    read(path) {
        return _fs.readFileSync(`${fs.dir}${path}`, { encoding: "utf8" });
    }
}


function initConstants() {
    for (let face of FACES) {
        for (let suit of SUITS) {
            const card = face + suit;
            CARD_ID[card] = ALL_CARDS.length;
            ALL_CARDS.push(card);
        }
    }
    for (let i = 0; i < 52; i++) {
        for (let j = i + 1; j < 52; j++) {
            const hand = ALL_CARDS[i] + ALL_CARDS[j];
            HAND_ID[hand] = ALL_HANDS.length;
            ALL_HANDS.push(hand);
        }
    }


    const preflopEquities = fs.read("data/preflop/random.txt");
    if (!preflopEquities || !preflopEquities.length) {
        throw Error("data/preflop/random.txt is invalid");
    }
    preflopEquities.split("\n").map(s => s.trim().split(" ")).forEach((arr) => {
        if (arr.length === 5) {
            PREFLOP_HAND_ID[arr[0]] = PREFLOP_HANDS.length;
            PREFLOP_HANDS.push(arr[0]);
            PREFLOP_EQUITY.push(parseFloat(arr[1]));
        }
    });
}

exports.fs = fs;
exports.FACES = FACES;
exports.SUITS = SUITS;
exports.ALL_CARDS = ALL_CARDS; //52
exports.CARD_ID = CARD_ID;
exports.ALL_HANDS = ALL_HANDS; //1326, sorted naively
exports.HAND_ID = HAND_ID;

exports.PREFLOP_HANDS = PREFLOP_HANDS; //169, sorted by preflop equity
exports.PREFLOP_EQUITY = PREFLOP_EQUITY;
exports.PREFLOP_HAND_ID = PREFLOP_HAND_ID;

exports.initConstants = initConstants;
