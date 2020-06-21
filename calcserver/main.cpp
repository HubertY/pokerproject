#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "omp/EquityCalculator.h"
#include "constants.h"
#include "util.h"
#include "calc.h"

#include "socket.h"

using namespace std;

void enumf(){
    for(int i = 0; i < 1755; i++){
        string flop = DISTINCT_FLOPS[i];
        cout << flop << " " << i << endl;
        writeFlopData("random", flop);
    }
}

void enumb(){
    for(int i = 1755; i--;){
        string flop = DISTINCT_FLOPS[i];
        cout << flop << " " << i << endl;
        writeFlopData("random", flop);
    }
}

void enummb(){
    for(int i = 1000; i--;){
        string flop = DISTINCT_FLOPS[i];
        cout << flop << " " << i << endl;
        writeFlopData("random", flop);
    }
}

const string configDirectory = "config.json";
int main() {
    cout << "reading config.json" << endl;
    ifstream fin;
    fin.open(configDirectory);
    string ip, _port;
    while (ip != "\"ip\":") {
        fin >> ip;
        if (fin.eof()) {
            throw "config.json invalid (dont mess with the whitespace!)";
        }
    }
    fin >> ip;
    ip = ip.substr(1, ip.length()-3);
    while (_port != "\"port\":") {
        fin >> _port;
        if (fin.eof()) {
            throw "config.json invalid (dont mess with the whitespace!)";
        }
    }
    fin >> _port;
    int port = std::stoi(_port.substr(1, _port.length() - 2));
    cout << ip << ":" << port << endl;

    cout << "intializing constants..." << endl;
    initConstants();

    initializeSocket(port);

    while(true){
        awaitMessage();
    }

    return 0;
}


