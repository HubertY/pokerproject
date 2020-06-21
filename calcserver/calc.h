#ifndef CALC_H
#define CALC_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "omp/EquityCalculator.h"
#include "constants.h"
#include "util.h"

using namespace std;

omp::EquityCalculator::Results getEquity(string hero, string villain = "random", string board = "") {
    omp::EquityCalculator eq;
    eq.start({ hero, villain }, omp::CardRange::getCardMask(board), 0, true);
    eq.wait();
    //cout << hero << " " << villain << " " << board << " " << eq.getResults().equity[0] << endl;
    return eq.getResults();
}



bool sortByEquity(pair<string, omp::EquityCalculator::Results>& x, pair<string, omp::EquityCalculator::Results>& y) {
    return x.second.equity[0] > y.second.equity[0];
}



vector<pair<string, omp::EquityCalculator::Results>> getPreflopVillains(string villain = "random") {
    vector<pair<string, omp::EquityCalculator::Results>> data;

    for (string hand : PREFLOP_HANDS) {
        auto eq = getEquity(hand, villain);
        data.push_back(make_pair(hand, eq));
    }

    sort(data.begin(), data.end(), sortByEquity);

    return data;
}

void writePreflopData(string villain) {
    auto data = getPreflopVillains(villain);
    ofstream fout;
    fout.open("data/preflop/" + villain + ".txt");
    for (auto hand : data) {
        fout << hand.first << " " << hand.second.equity[0] << " " << hand.second.wins[0] << " " << hand.second.ties[0] << " " << hand.second.hands << endl;
    }
    fout.close();
}

void writeAllPreflopData() {
    for (auto hand : PREFLOP_HANDS) {
        writePreflopData(hand);
    }
}


void mkdir(string path) {
    std::wstring ws = std::wstring(path.begin(), path.end());
    mkdir(path);
}

bool consistent(string first, string second) {
    return (omp::CardRange::getCardMask(first) & omp::CardRange::getCardMask(second)) == 0;
}

vector<pair<string, omp::EquityCalculator::Results>> getVillains(string villain = "random", string board = "") {
    vector<pair<string, omp::EquityCalculator::Results>> data;

    for (string hand : ALL_HANDS) {
        if (consistent(hand, villain) && consistent(hand, board)) {
            auto eq = getEquity(hand, villain, board);
            data.push_back(make_pair(hand, eq));
        }
    }

    sort(data.begin(), data.end(), sortByEquity);

    return data;
}



void writeFlopData(string villain, string board) {
    string path = "data/flop/" + board + ".txt";
    if (ifstream(path).good()) {
        return;
    }

    auto data = getVillains(villain, board);
    ofstream fout;
    fout.open(path);
    for (auto hand : data) {
        fout << hand.first << " " << hand.second.equity[0] << " " << hand.second.wins[0] << " " << hand.second.ties[0] << " " << hand.second.hands << endl;
    }
    fout.close();
}

#endif