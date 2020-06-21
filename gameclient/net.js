const net = require("net");

const {ALL_HANDS, HAND_ID} = require("./constants.js");

class TCPConnection {
    async connect() {
        return new Promise((resolve) => {
            this.sock.connect(this.port, this.ip, resolve);
        });
    }
    sendMessage(data) {
        return new Promise((resolve) => {
            this.sock.write(data, resolve);
        });
    }
    async nextMessage() {
        return new Promise((resolve) => {
            if (this.dataQueue.length) {
                resolve(this.dataQueue.pop());
            }
            else {
                this.hook = resolve;
            }
        });
    }
    flush() {
        this.hook = null;
        this.dataQueue = [];
    }
    constructor({ ip, port }) {
        this.ip = ip;
        this.port = port;
        this.dataQueue = [];
        this.hook = null;
        this.sock = new net.Socket();
        this.sock.on('data', (data) => {
            data = data.toString();
            if (this.hook) {
                this.hook(data);
            }
            else {
                this.dataQueue.unshift(data);
            }
        });
    }
}

class CalcServ{
    stream(request, cb){
        this.connection.flush();
        this.connection.sendMessage(request);
        (async ()=>{
            let msg = "";
            while(msg !== "STOPACK"){
                if(msg.length){
                    cb(msg);
                }
                msg = await this.connection.nextMessage();
            }
            console.log("stream stopped");
        })();
        return {
            stop: ()=>{
                this.connection.sendMessage("STOP");
            }
        };
    }
    async request(request){
        this.connection.sendMessage(request);
        return await this.connection.nextMessage();
    }
    async getVillains(hand, board){
        let ret = [];
        for(let hand of ALL_HANDS){
            ret.push(0);
        }
        let str = await this.request(`REQUEST VILLAINS ${hand} ${board}`);
        let strs = str.split("\n");
        for(let s of strs){
            s = s.trim();
            if(s.length){
                const [hand, equity] = s.split(" ");
                ret[HAND_ID[hand]] = parseFloat(equity);
            }
        }
        return ret;
    }
    constructor(connection){
        this.connection = connection;
    }
};

exports.TCPConnection = TCPConnection;
exports.CalcServ = CalcServ;