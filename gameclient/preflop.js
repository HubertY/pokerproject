const {FACES, SUITS, ALL_CARDS, CARD_ID, ALL_HANDS, HAND_ID, PREFLOP_HANDS, PREFLOP_EQUITY, PREFLOP_HAND_ID} = require("./constants.js");
const {normalize} = require("./util.js");


function prefloppify(hand) {
    return hand[0] === hand[2] ? hand[0] + hand[2] : hand[0] + hand[2] + (hand[1] === hand[3] ? "s" : "o");
}


const preflopRange1 = 0.8;
const preflopBet1 = 300;
const preflop4CallRange1 = 0.3;


const preflop3CallRange0 = 0.6;
const preflop3BetRange0 = 0.2;
const preflop3BetSize0 = 1000;
const preflop5CallRange0 = 0.1;

function expma(n, c, q = 0.95){
    return q*n+(1-q)*c;
}

//window of 100 hands
class PreflopTracker {
    query(actions, opposition){
        let ret = [];
        let range = [1,0];
        if(opposition === 1){
            if(actions[0].type === "f"){
                range = [1, this.c1];
            }
            else if(actions[0].type === "c"){
                range = [this.c1, this.r1];
            }
            else if(actions[0].type === "r"){
                range = [this.r1, 0];
                if(actions[2]){
                    if(actions[2].type === "f"){
                        range = [this.r1, this.rc1];
                    }
                    else if(actions[2].type === "c"){
                        range = [this.rc1, this.rr1];
                    }
                    else if(actions[2].type === "r"){
                        range = [this.rr1, 0];
                    }
                }
            }
        }
        if(opposition === 0){
            if(actions[1]){
                if(actions[1].type === "f"){
                    range = [1, this.c0];
                }
                else if(actions[1].type === "c"){
                    range = [this.c0, this.r0];
                }
                else if(actions[1].type === "r"){
                    range = [this.r0, 0];
                }
            }
        }
        for(let hand of ALL_HANDS){
            let ranking = PREFLOP_HAND_ID[prefloppify(hand)]/169;
            if(ranking >= range[1] && ranking <= range[0]){
                ret[HAND_ID[hand]] = 3;
            }
            else{
                ret[HAND_ID[hand]] = 1;
            }
        }
        return normalize(ret);
    }
    feed(actions, opposition, ophand = null){
        if(opposition === 1){
            if(actions[0].type === "f"){
                this.c1 = expma(this.c1, 0); 
                this.r1 = expma(this.r1, 0); 
                this.rc1 = this.rc1 = expma(this.rc1, 0);
                this.rr1 = this.rr1 = expma(this.rr1, 0); 
            }
            else if(actions[0].type === "c"){
                this.c1 = expma(this.c1, 1); 
                this.r1 = expma(this.r1, 0); 
                this.rc1 = this.rc1 = expma(this.rc1, 0);
                this.rr1 = this.rr1 = expma(this.rr1, 0); 
            }
            else if(actions[0].type === "r"){
                this.c1 = expma(this.c1, 1); 
                this.r1 = expma(this.r1, 1); 
                if(actions[2]){
                    if(actions[2].type === "f"){
                        this.rc1 = this.rc1 = expma(this.rc1, 0);
                        this.rr1 = this.rr1 = expma(this.rr1, 0); 
                    }
                    else if(actions[2].type === "c"){
                        this.rc1 = this.rc1 = expma(this.rc1, 1);
                        this.rr1 = this.rr1 = expma(this.rr1, 0); 
                    }
                    else if(actions[2].type === "r"){
                        this.rc1 = this.rc1 = expma(this.rc1, 1);
                        this.rr1 = this.rr1 = expma(this.rr1, 1); 
                    }
                }
            }
        }
        if(opposition === 0){
            if(actions[1]){
                if(actions[1].type === "f"){
                    this.c0 = this.c0 = expma(this.c0, 0);
                    this.r0 = this.r0 = expma(this.r0, 0); 
                }
                else if(actions[1].type === "c"){
                    this.c0 = this.c0 = expma(this.c0, 0);
                    this.r0 = this.r0 = expma(this.r0, 1); 
                }
                else if(actions[1].type === "r"){
                    this.c0 = this.c0 = expma(this.c0, 1);
                    this.r0 = this.r0 = expma(this.r0, 1); 
                }
            }
        }
    }
    constructor(){
        //sb open call range
        this.c1 = 1;
        //sb open bet range
        this.r1 = 0.8;
        //sb 4call call range
        this.rc1 = 0.3;
        //sb 4bet range
        this.rr1 = 0.1;

        //bb 3call range
        this.c0 = 0.6;
        //bb 3bet range
        this.r0 = 0.2;
    }
}


function playPreflop(hand, preflop, position){
    const pfhand = prefloppify(hand);
    if (position === 1) {
        //small blind
        if (preflop.length === 0) {
            //open
            console.log(`hand rank ${PREFLOP_HAND_ID[pfhand]}/169 (${PREFLOP_HAND_ID[pfhand] / 169} loss)`);
            if (PREFLOP_HAND_ID[pfhand] / 169 > preflopRange1) {
                return "f";
            }
            else {
                return `r${preflopBet1}`;
            }
        }
        else if (preflop.length === 2) {
            //opponent 3-bet
            let amount = preflop[preflop.length - 1].value;
            let adjustedrange = preflop4CallRange1;

            if (PREFLOP_HAND_ID[pfhand] / 169 > adjustedrange) {
                return "f";
            }
            else {
                return "c";
            }
        }
    }
    else if (position === 0) {
        //big blind
        if (preflop.length === 1) {
            if (preflop[0].type === "c") {
                //call limps
                return "c";
            }
            else if (preflop[0].type === "r") {
                //call/3bet bets
                let amount = preflop[preflop.length - 1].value;
                console.log(`hand rank ${PREFLOP_HAND_ID[pfhand]}/169 (${PREFLOP_HAND_ID[pfhand] / 169} loss)`);
                
                if (PREFLOP_HAND_ID[pfhand] / 169 > preflop3CallRange0) {
                    return "f";
                }
                else if (PREFLOP_HAND_ID[pfhand] / 169 > preflop3BetRange0) {
                    return "c";
                }
                else {
                    if(amount > 500){
                        return "c";
                    }
                    else{
                        return `r${preflop3BetSize0}`;
                    }

                }
            }
        }
        else if (preflop.length === 3) {
            if (preflop[0].type === "r") {
                //opponent 4-bet
                let amount = preflop[preflop.length - 1].value;
                if (PREFLOP_HAND_ID[pfhand] / 169 > preflop5CallRange0) {
                    return "f";
                }
                else {
                    return "c";
                }
            }
        }
    }
}

exports.playPreflop = playPreflop;
exports.prefloppify = prefloppify;
exports.PreflopTracker = PreflopTracker;