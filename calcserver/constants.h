#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <map>
#include <fstream>

#include "util.h"


omp::EquityCalculator CALC;

std::string cards[13] = { "A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2" };
std::string suits[4] = { "s", "h", "d", "c" };
std::string PREFLOP_HANDS[169] = {};
std::map<std::string, int> PREFLOP_HAND_ID;

std::string ALL_CARDS[52];
std::string ALL_HANDS[1326];

std::string DISTINCT_FLOPS[1755] = { "2c2d2h", "2c2d3d", "2c2d3h", "2c2d4d", "2c2d4h", "2c2d5d", "2c2d5h", "2c2d6d", "2c2d6h", "2c2d7d", "2c2d7h", "2c2d8d", "2c2d8h", "2c2d9d", "2c2d9h", "2c2dTd", "2c2dTh", "2c2dJd", "2c2dJh", "2c2dQd", "2c2dQh", "2c2dKd", "2c2dKh", "2c2dAd", "2c2dAh", "2c3c3d", "2c3c4c", "2c3c4d", "2c3c5c", "2c3c5d", "2c3c6c", "2c3c6d", "2c3c7c", "2c3c7d", "2c3c8c", "2c3c8d", "2c3c9c", "2c3c9d", "2c3cTc", "2c3cTd", "2c3cJc", "2c3cJd", "2c3cQc", "2c3cQd", "2c3cKc", "2c3cKd", "2c3cAc", "2c3cAd", "2c3d3h", "2c3d4c", "2c3d4d", "2c3d4h", "2c3d5c", "2c3d5d", "2c3d5h", "2c3d6c", "2c3d6d", "2c3d6h", "2c3d7c", "2c3d7d", "2c3d7h", "2c3d8c", "2c3d8d", "2c3d8h", "2c3d9c", "2c3d9d", "2c3d9h", "2c3dTc", "2c3dTd", "2c3dTh", "2c3dJc", "2c3dJd", "2c3dJh", "2c3dQc", "2c3dQd", "2c3dQh", "2c3dKc", "2c3dKd", "2c3dKh", "2c3dAc", "2c3dAd", "2c3dAh", "2c4c4d", "2c4c5c", "2c4c5d", "2c4c6c", "2c4c6d", "2c4c7c", "2c4c7d", "2c4c8c", "2c4c8d", "2c4c9c", "2c4c9d", "2c4cTc", "2c4cTd", "2c4cJc", "2c4cJd", "2c4cQc", "2c4cQd", "2c4cKc", "2c4cKd", "2c4cAc", "2c4cAd", "2c4d4h", "2c4d5c", "2c4d5d", "2c4d5h", "2c4d6c", "2c4d6d", "2c4d6h", "2c4d7c", "2c4d7d", "2c4d7h", "2c4d8c", "2c4d8d", "2c4d8h", "2c4d9c", "2c4d9d", "2c4d9h", "2c4dTc", "2c4dTd", "2c4dTh", "2c4dJc", "2c4dJd", "2c4dJh", "2c4dQc", "2c4dQd", "2c4dQh", "2c4dKc", "2c4dKd", "2c4dKh", "2c4dAc", "2c4dAd", "2c4dAh", "2c5c5d", "2c5c6c", "2c5c6d", "2c5c7c", "2c5c7d", "2c5c8c", "2c5c8d", "2c5c9c", "2c5c9d", "2c5cTc", "2c5cTd", "2c5cJc", "2c5cJd", "2c5cQc", "2c5cQd", "2c5cKc", "2c5cKd", "2c5cAc", "2c5cAd", "2c5d5h", "2c5d6c", "2c5d6d", "2c5d6h", "2c5d7c", "2c5d7d", "2c5d7h", "2c5d8c", "2c5d8d", "2c5d8h", "2c5d9c", "2c5d9d", "2c5d9h", "2c5dTc", "2c5dTd", "2c5dTh", "2c5dJc", "2c5dJd", "2c5dJh", "2c5dQc", "2c5dQd", "2c5dQh", "2c5dKc", "2c5dKd", "2c5dKh", "2c5dAc", "2c5dAd", "2c5dAh", "2c6c6d", "2c6c7c", "2c6c7d", "2c6c8c", "2c6c8d", "2c6c9c", "2c6c9d", "2c6cTc", "2c6cTd", "2c6cJc", "2c6cJd", "2c6cQc", "2c6cQd", "2c6cKc", "2c6cKd", "2c6cAc", "2c6cAd", "2c6d6h", "2c6d7c", "2c6d7d", "2c6d7h", "2c6d8c", "2c6d8d", "2c6d8h", "2c6d9c", "2c6d9d", "2c6d9h", "2c6dTc", "2c6dTd", "2c6dTh", "2c6dJc", "2c6dJd", "2c6dJh", "2c6dQc", "2c6dQd", "2c6dQh", "2c6dKc", "2c6dKd", "2c6dKh", "2c6dAc", "2c6dAd", "2c6dAh", "2c7c7d", "2c7c8c", "2c7c8d", "2c7c9c", "2c7c9d", "2c7cTc", "2c7cTd", "2c7cJc", "2c7cJd", "2c7cQc", "2c7cQd", "2c7cKc", "2c7cKd", "2c7cAc", "2c7cAd", "2c7d7h", "2c7d8c", "2c7d8d", "2c7d8h", "2c7d9c", "2c7d9d", "2c7d9h", "2c7dTc", "2c7dTd", "2c7dTh", "2c7dJc", "2c7dJd", "2c7dJh", "2c7dQc", "2c7dQd", "2c7dQh", "2c7dKc", "2c7dKd", "2c7dKh", "2c7dAc", "2c7dAd", "2c7dAh", "2c8c8d", "2c8c9c", "2c8c9d", "2c8cTc", "2c8cTd", "2c8cJc", "2c8cJd", "2c8cQc", "2c8cQd", "2c8cKc", "2c8cKd", "2c8cAc", "2c8cAd", "2c8d8h", "2c8d9c", "2c8d9d", "2c8d9h", "2c8dTc", "2c8dTd", "2c8dTh", "2c8dJc", "2c8dJd", "2c8dJh", "2c8dQc", "2c8dQd", "2c8dQh", "2c8dKc", "2c8dKd", "2c8dKh", "2c8dAc", "2c8dAd", "2c8dAh", "2c9c9d", "2c9cTc", "2c9cTd", "2c9cJc", "2c9cJd", "2c9cQc", "2c9cQd", "2c9cKc", "2c9cKd", "2c9cAc", "2c9cAd", "2c9d9h", "2c9dTc", "2c9dTd", "2c9dTh", "2c9dJc", "2c9dJd", "2c9dJh", "2c9dQc", "2c9dQd", "2c9dQh", "2c9dKc", "2c9dKd", "2c9dKh", "2c9dAc", "2c9dAd", "2c9dAh", "2cTcTd", "2cTcJc", "2cTcJd", "2cTcQc", "2cTcQd", "2cTcKc", "2cTcKd", "2cTcAc", "2cTcAd", "2cTdTh", "2cTdJc", "2cTdJd", "2cTdJh", "2cTdQc", "2cTdQd", "2cTdQh", "2cTdKc", "2cTdKd", "2cTdKh", "2cTdAc", "2cTdAd", "2cTdAh", "2cJcJd", "2cJcQc", "2cJcQd", "2cJcKc", "2cJcKd", "2cJcAc", "2cJcAd", "2cJdJh", "2cJdQc", "2cJdQd", "2cJdQh", "2cJdKc", "2cJdKd", "2cJdKh", "2cJdAc", "2cJdAd", "2cJdAh", "2cQcQd", "2cQcKc", "2cQcKd", "2cQcAc", "2cQcAd", "2cQdQh", "2cQdKc", "2cQdKd", "2cQdKh", "2cQdAc", "2cQdAd", "2cQdAh", "2cKcKd", "2cKcAc", "2cKcAd", "2cKdKh", "2cKdAc", "2cKdAd", "2cKdAh", "2cAcAd", "2cAdAh", "3c3d3h", "3c3d4d", "3c3d4h", "3c3d5d", "3c3d5h", "3c3d6d", "3c3d6h", "3c3d7d", "3c3d7h", "3c3d8d", "3c3d8h", "3c3d9d", "3c3d9h", "3c3dTd", "3c3dTh", "3c3dJd", "3c3dJh", "3c3dQd", "3c3dQh", "3c3dKd", "3c3dKh", "3c3dAd", "3c3dAh", "3c4c4d", "3c4c5c", "3c4c5d", "3c4c6c", "3c4c6d", "3c4c7c", "3c4c7d", "3c4c8c", "3c4c8d", "3c4c9c", "3c4c9d", "3c4cTc", "3c4cTd", "3c4cJc", "3c4cJd", "3c4cQc", "3c4cQd", "3c4cKc", "3c4cKd", "3c4cAc", "3c4cAd", "3c4d4h", "3c4d5c", "3c4d5d", "3c4d5h", "3c4d6c", "3c4d6d", "3c4d6h", "3c4d7c", "3c4d7d", "3c4d7h", "3c4d8c", "3c4d8d", "3c4d8h", "3c4d9c", "3c4d9d", "3c4d9h", "3c4dTc", "3c4dTd", "3c4dTh", "3c4dJc", "3c4dJd", "3c4dJh", "3c4dQc", "3c4dQd", "3c4dQh", "3c4dKc", "3c4dKd", "3c4dKh", "3c4dAc", "3c4dAd", "3c4dAh", "3c5c5d", "3c5c6c", "3c5c6d", "3c5c7c", "3c5c7d", "3c5c8c", "3c5c8d", "3c5c9c", "3c5c9d", "3c5cTc", "3c5cTd", "3c5cJc", "3c5cJd", "3c5cQc", "3c5cQd", "3c5cKc", "3c5cKd", "3c5cAc", "3c5cAd", "3c5d5h", "3c5d6c", "3c5d6d", "3c5d6h", "3c5d7c", "3c5d7d", "3c5d7h", "3c5d8c", "3c5d8d", "3c5d8h", "3c5d9c", "3c5d9d", "3c5d9h", "3c5dTc", "3c5dTd", "3c5dTh", "3c5dJc", "3c5dJd", "3c5dJh", "3c5dQc", "3c5dQd", "3c5dQh", "3c5dKc", "3c5dKd", "3c5dKh", "3c5dAc", "3c5dAd", "3c5dAh", "3c6c6d", "3c6c7c", "3c6c7d", "3c6c8c", "3c6c8d", "3c6c9c", "3c6c9d", "3c6cTc", "3c6cTd", "3c6cJc", "3c6cJd", "3c6cQc", "3c6cQd", "3c6cKc", "3c6cKd", "3c6cAc", "3c6cAd", "3c6d6h", "3c6d7c", "3c6d7d", "3c6d7h", "3c6d8c", "3c6d8d", "3c6d8h", "3c6d9c", "3c6d9d", "3c6d9h", "3c6dTc", "3c6dTd", "3c6dTh", "3c6dJc", "3c6dJd", "3c6dJh", "3c6dQc", "3c6dQd", "3c6dQh", "3c6dKc", "3c6dKd", "3c6dKh", "3c6dAc", "3c6dAd", "3c6dAh", "3c7c7d", "3c7c8c", "3c7c8d", "3c7c9c", "3c7c9d", "3c7cTc", "3c7cTd", "3c7cJc", "3c7cJd", "3c7cQc", "3c7cQd", "3c7cKc", "3c7cKd", "3c7cAc", "3c7cAd", "3c7d7h", "3c7d8c", "3c7d8d", "3c7d8h", "3c7d9c", "3c7d9d", "3c7d9h", "3c7dTc", "3c7dTd", "3c7dTh", "3c7dJc", "3c7dJd", "3c7dJh", "3c7dQc", "3c7dQd", "3c7dQh", "3c7dKc", "3c7dKd", "3c7dKh", "3c7dAc", "3c7dAd", "3c7dAh", "3c8c8d", "3c8c9c", "3c8c9d", "3c8cTc", "3c8cTd", "3c8cJc", "3c8cJd", "3c8cQc", "3c8cQd", "3c8cKc", "3c8cKd", "3c8cAc", "3c8cAd", "3c8d8h", "3c8d9c", "3c8d9d", "3c8d9h", "3c8dTc", "3c8dTd", "3c8dTh", "3c8dJc", "3c8dJd", "3c8dJh", "3c8dQc", "3c8dQd", "3c8dQh", "3c8dKc", "3c8dKd", "3c8dKh", "3c8dAc", "3c8dAd", "3c8dAh", "3c9c9d", "3c9cTc", "3c9cTd", "3c9cJc", "3c9cJd", "3c9cQc", "3c9cQd", "3c9cKc", "3c9cKd", "3c9cAc", "3c9cAd", "3c9d9h", "3c9dTc", "3c9dTd", "3c9dTh", "3c9dJc", "3c9dJd", "3c9dJh", "3c9dQc", "3c9dQd", "3c9dQh", "3c9dKc", "3c9dKd", "3c9dKh", "3c9dAc", "3c9dAd", "3c9dAh", "3cTcTd", "3cTcJc", "3cTcJd", "3cTcQc", "3cTcQd", "3cTcKc", "3cTcKd", "3cTcAc", "3cTcAd", "3cTdTh", "3cTdJc", "3cTdJd", "3cTdJh", "3cTdQc", "3cTdQd", "3cTdQh", "3cTdKc", "3cTdKd", "3cTdKh", "3cTdAc", "3cTdAd", "3cTdAh", "3cJcJd", "3cJcQc", "3cJcQd", "3cJcKc", "3cJcKd", "3cJcAc", "3cJcAd", "3cJdJh", "3cJdQc", "3cJdQd", "3cJdQh", "3cJdKc", "3cJdKd", "3cJdKh", "3cJdAc", "3cJdAd", "3cJdAh", "3cQcQd", "3cQcKc", "3cQcKd", "3cQcAc", "3cQcAd", "3cQdQh", "3cQdKc", "3cQdKd", "3cQdKh", "3cQdAc", "3cQdAd", "3cQdAh", "3cKcKd", "3cKcAc", "3cKcAd", "3cKdKh", "3cKdAc", "3cKdAd", "3cKdAh", "3cAcAd", "3cAdAh", "4c4d4h", "4c4d5d", "4c4d5h", "4c4d6d", "4c4d6h", "4c4d7d", "4c4d7h", "4c4d8d", "4c4d8h", "4c4d9d", "4c4d9h", "4c4dTd", "4c4dTh", "4c4dJd", "4c4dJh", "4c4dQd", "4c4dQh", "4c4dKd", "4c4dKh", "4c4dAd", "4c4dAh", "4c5c5d", "4c5c6c", "4c5c6d", "4c5c7c", "4c5c7d", "4c5c8c", "4c5c8d", "4c5c9c", "4c5c9d", "4c5cTc", "4c5cTd", "4c5cJc", "4c5cJd", "4c5cQc", "4c5cQd", "4c5cKc", "4c5cKd", "4c5cAc", "4c5cAd", "4c5d5h", "4c5d6c", "4c5d6d", "4c5d6h", "4c5d7c", "4c5d7d", "4c5d7h", "4c5d8c", "4c5d8d", "4c5d8h", "4c5d9c", "4c5d9d", "4c5d9h", "4c5dTc", "4c5dTd", "4c5dTh", "4c5dJc", "4c5dJd", "4c5dJh", "4c5dQc", "4c5dQd", "4c5dQh", "4c5dKc", "4c5dKd", "4c5dKh", "4c5dAc", "4c5dAd", "4c5dAh", "4c6c6d", "4c6c7c", "4c6c7d", "4c6c8c", "4c6c8d", "4c6c9c", "4c6c9d", "4c6cTc", "4c6cTd", "4c6cJc", "4c6cJd", "4c6cQc", "4c6cQd", "4c6cKc", "4c6cKd", "4c6cAc", "4c6cAd", "4c6d6h", "4c6d7c", "4c6d7d", "4c6d7h", "4c6d8c", "4c6d8d", "4c6d8h", "4c6d9c", "4c6d9d", "4c6d9h", "4c6dTc", "4c6dTd", "4c6dTh", "4c6dJc", "4c6dJd", "4c6dJh", "4c6dQc", "4c6dQd", "4c6dQh", "4c6dKc", "4c6dKd", "4c6dKh", "4c6dAc", "4c6dAd", "4c6dAh", "4c7c7d", "4c7c8c", "4c7c8d", "4c7c9c", "4c7c9d", "4c7cTc", "4c7cTd", "4c7cJc", "4c7cJd", "4c7cQc", "4c7cQd", "4c7cKc", "4c7cKd", "4c7cAc", "4c7cAd", "4c7d7h", "4c7d8c", "4c7d8d", "4c7d8h", "4c7d9c", "4c7d9d", "4c7d9h", "4c7dTc", "4c7dTd", "4c7dTh", "4c7dJc", "4c7dJd", "4c7dJh", "4c7dQc", "4c7dQd", "4c7dQh", "4c7dKc", "4c7dKd", "4c7dKh", "4c7dAc", "4c7dAd", "4c7dAh", "4c8c8d", "4c8c9c", "4c8c9d", "4c8cTc", "4c8cTd", "4c8cJc", "4c8cJd", "4c8cQc", "4c8cQd", "4c8cKc", "4c8cKd", "4c8cAc", "4c8cAd", "4c8d8h", "4c8d9c", "4c8d9d", "4c8d9h", "4c8dTc", "4c8dTd", "4c8dTh", "4c8dJc", "4c8dJd", "4c8dJh", "4c8dQc", "4c8dQd", "4c8dQh", "4c8dKc", "4c8dKd", "4c8dKh", "4c8dAc", "4c8dAd", "4c8dAh", "4c9c9d", "4c9cTc", "4c9cTd", "4c9cJc", "4c9cJd", "4c9cQc", "4c9cQd", "4c9cKc", "4c9cKd", "4c9cAc", "4c9cAd", "4c9d9h", "4c9dTc", "4c9dTd", "4c9dTh", "4c9dJc", "4c9dJd", "4c9dJh", "4c9dQc", "4c9dQd", "4c9dQh", "4c9dKc", "4c9dKd", "4c9dKh", "4c9dAc", "4c9dAd", "4c9dAh", "4cTcTd", "4cTcJc", "4cTcJd", "4cTcQc", "4cTcQd", "4cTcKc", "4cTcKd", "4cTcAc", "4cTcAd", "4cTdTh", "4cTdJc", "4cTdJd", "4cTdJh", "4cTdQc", "4cTdQd", "4cTdQh", "4cTdKc", "4cTdKd", "4cTdKh", "4cTdAc", "4cTdAd", "4cTdAh", "4cJcJd", "4cJcQc", "4cJcQd", "4cJcKc", "4cJcKd", "4cJcAc", "4cJcAd", "4cJdJh", "4cJdQc", "4cJdQd", "4cJdQh", "4cJdKc", "4cJdKd", "4cJdKh", "4cJdAc", "4cJdAd", "4cJdAh", "4cQcQd", "4cQcKc", "4cQcKd", "4cQcAc", "4cQcAd", "4cQdQh", "4cQdKc", "4cQdKd", "4cQdKh", "4cQdAc", "4cQdAd", "4cQdAh", "4cKcKd", "4cKcAc", "4cKcAd", "4cKdKh", "4cKdAc", "4cKdAd", "4cKdAh", "4cAcAd", "4cAdAh", "5c5d5h", "5c5d6d", "5c5d6h", "5c5d7d", "5c5d7h", "5c5d8d", "5c5d8h", "5c5d9d", "5c5d9h", "5c5dTd", "5c5dTh", "5c5dJd", "5c5dJh", "5c5dQd", "5c5dQh", "5c5dKd", "5c5dKh", "5c5dAd", "5c5dAh", "5c6c6d", "5c6c7c", "5c6c7d", "5c6c8c", "5c6c8d", "5c6c9c", "5c6c9d", "5c6cTc", "5c6cTd", "5c6cJc", "5c6cJd", "5c6cQc", "5c6cQd", "5c6cKc", "5c6cKd", "5c6cAc", "5c6cAd", "5c6d6h", "5c6d7c", "5c6d7d", "5c6d7h", "5c6d8c", "5c6d8d", "5c6d8h", "5c6d9c", "5c6d9d", "5c6d9h", "5c6dTc", "5c6dTd", "5c6dTh", "5c6dJc", "5c6dJd", "5c6dJh", "5c6dQc", "5c6dQd", "5c6dQh", "5c6dKc", "5c6dKd", "5c6dKh", "5c6dAc", "5c6dAd", "5c6dAh", "5c7c7d", "5c7c8c", "5c7c8d", "5c7c9c", "5c7c9d", "5c7cTc", "5c7cTd", "5c7cJc", "5c7cJd", "5c7cQc", "5c7cQd", "5c7cKc", "5c7cKd", "5c7cAc", "5c7cAd", "5c7d7h", "5c7d8c", "5c7d8d", "5c7d8h", "5c7d9c", "5c7d9d", "5c7d9h", "5c7dTc", "5c7dTd", "5c7dTh", "5c7dJc", "5c7dJd", "5c7dJh", "5c7dQc", "5c7dQd", "5c7dQh", "5c7dKc", "5c7dKd", "5c7dKh", "5c7dAc", "5c7dAd", "5c7dAh", "5c8c8d", "5c8c9c", "5c8c9d", "5c8cTc", "5c8cTd", "5c8cJc", "5c8cJd", "5c8cQc", "5c8cQd", "5c8cKc", "5c8cKd", "5c8cAc", "5c8cAd", "5c8d8h", "5c8d9c", "5c8d9d", "5c8d9h", "5c8dTc", "5c8dTd", "5c8dTh", "5c8dJc", "5c8dJd", "5c8dJh", "5c8dQc", "5c8dQd", "5c8dQh", "5c8dKc", "5c8dKd", "5c8dKh", "5c8dAc", "5c8dAd", "5c8dAh", "5c9c9d", "5c9cTc", "5c9cTd", "5c9cJc", "5c9cJd", "5c9cQc", "5c9cQd", "5c9cKc", "5c9cKd", "5c9cAc", "5c9cAd", "5c9d9h", "5c9dTc", "5c9dTd", "5c9dTh", "5c9dJc", "5c9dJd", "5c9dJh", "5c9dQc", "5c9dQd", "5c9dQh", "5c9dKc", "5c9dKd", "5c9dKh", "5c9dAc", "5c9dAd", "5c9dAh", "5cTcTd", "5cTcJc", "5cTcJd", "5cTcQc", "5cTcQd", "5cTcKc", "5cTcKd", "5cTcAc", "5cTcAd", "5cTdTh", "5cTdJc", "5cTdJd", "5cTdJh", "5cTdQc", "5cTdQd", "5cTdQh", "5cTdKc", "5cTdKd", "5cTdKh", "5cTdAc", "5cTdAd", "5cTdAh", "5cJcJd", "5cJcQc", "5cJcQd", "5cJcKc", "5cJcKd", "5cJcAc", "5cJcAd", "5cJdJh", "5cJdQc", "5cJdQd", "5cJdQh", "5cJdKc", "5cJdKd", "5cJdKh", "5cJdAc", "5cJdAd", "5cJdAh", "5cQcQd", "5cQcKc", "5cQcKd", "5cQcAc", "5cQcAd", "5cQdQh", "5cQdKc", "5cQdKd", "5cQdKh", "5cQdAc", "5cQdAd", "5cQdAh", "5cKcKd", "5cKcAc", "5cKcAd", "5cKdKh", "5cKdAc", "5cKdAd", "5cKdAh", "5cAcAd", "5cAdAh", "6c6d6h", "6c6d7d", "6c6d7h", "6c6d8d", "6c6d8h", "6c6d9d", "6c6d9h", "6c6dTd", "6c6dTh", "6c6dJd", "6c6dJh", "6c6dQd", "6c6dQh", "6c6dKd", "6c6dKh", "6c6dAd", "6c6dAh", "6c7c7d", "6c7c8c", "6c7c8d", "6c7c9c", "6c7c9d", "6c7cTc", "6c7cTd", "6c7cJc", "6c7cJd", "6c7cQc", "6c7cQd", "6c7cKc", "6c7cKd", "6c7cAc", "6c7cAd", "6c7d7h", "6c7d8c", "6c7d8d", "6c7d8h", "6c7d9c", "6c7d9d", "6c7d9h", "6c7dTc", "6c7dTd", "6c7dTh", "6c7dJc", "6c7dJd", "6c7dJh", "6c7dQc", "6c7dQd", "6c7dQh", "6c7dKc", "6c7dKd", "6c7dKh", "6c7dAc", "6c7dAd", "6c7dAh", "6c8c8d", "6c8c9c", "6c8c9d", "6c8cTc", "6c8cTd", "6c8cJc", "6c8cJd", "6c8cQc", "6c8cQd", "6c8cKc", "6c8cKd", "6c8cAc", "6c8cAd", "6c8d8h", "6c8d9c", "6c8d9d", "6c8d9h", "6c8dTc", "6c8dTd", "6c8dTh", "6c8dJc", "6c8dJd", "6c8dJh", "6c8dQc", "6c8dQd", "6c8dQh", "6c8dKc", "6c8dKd", "6c8dKh", "6c8dAc", "6c8dAd", "6c8dAh", "6c9c9d", "6c9cTc", "6c9cTd", "6c9cJc", "6c9cJd", "6c9cQc", "6c9cQd", "6c9cKc", "6c9cKd", "6c9cAc", "6c9cAd", "6c9d9h", "6c9dTc", "6c9dTd", "6c9dTh", "6c9dJc", "6c9dJd", "6c9dJh", "6c9dQc", "6c9dQd", "6c9dQh", "6c9dKc", "6c9dKd", "6c9dKh", "6c9dAc", "6c9dAd", "6c9dAh", "6cTcTd", "6cTcJc", "6cTcJd", "6cTcQc", "6cTcQd", "6cTcKc", "6cTcKd", "6cTcAc", "6cTcAd", "6cTdTh", "6cTdJc", "6cTdJd", "6cTdJh", "6cTdQc", "6cTdQd", "6cTdQh", "6cTdKc", "6cTdKd", "6cTdKh", "6cTdAc", "6cTdAd", "6cTdAh", "6cJcJd", "6cJcQc", "6cJcQd", "6cJcKc", "6cJcKd", "6cJcAc", "6cJcAd", "6cJdJh", "6cJdQc", "6cJdQd", "6cJdQh", "6cJdKc", "6cJdKd", "6cJdKh", "6cJdAc", "6cJdAd", "6cJdAh", "6cQcQd", "6cQcKc", "6cQcKd", "6cQcAc", "6cQcAd", "6cQdQh", "6cQdKc", "6cQdKd", "6cQdKh", "6cQdAc", "6cQdAd", "6cQdAh", "6cKcKd", "6cKcAc", "6cKcAd", "6cKdKh", "6cKdAc", "6cKdAd", "6cKdAh", "6cAcAd", "6cAdAh", "7c7d7h", "7c7d8d", "7c7d8h", "7c7d9d", "7c7d9h", "7c7dTd", "7c7dTh", "7c7dJd", "7c7dJh", "7c7dQd", "7c7dQh", "7c7dKd", "7c7dKh", "7c7dAd", "7c7dAh", "7c8c8d", "7c8c9c", "7c8c9d", "7c8cTc", "7c8cTd", "7c8cJc", "7c8cJd", "7c8cQc", "7c8cQd", "7c8cKc", "7c8cKd", "7c8cAc", "7c8cAd", "7c8d8h", "7c8d9c", "7c8d9d", "7c8d9h", "7c8dTc", "7c8dTd", "7c8dTh", "7c8dJc", "7c8dJd", "7c8dJh", "7c8dQc", "7c8dQd", "7c8dQh", "7c8dKc", "7c8dKd", "7c8dKh", "7c8dAc", "7c8dAd", "7c8dAh", "7c9c9d", "7c9cTc", "7c9cTd", "7c9cJc", "7c9cJd", "7c9cQc", "7c9cQd", "7c9cKc", "7c9cKd", "7c9cAc", "7c9cAd", "7c9d9h", "7c9dTc", "7c9dTd", "7c9dTh", "7c9dJc", "7c9dJd", "7c9dJh", "7c9dQc", "7c9dQd", "7c9dQh", "7c9dKc", "7c9dKd", "7c9dKh", "7c9dAc", "7c9dAd", "7c9dAh", "7cTcTd", "7cTcJc", "7cTcJd", "7cTcQc", "7cTcQd", "7cTcKc", "7cTcKd", "7cTcAc", "7cTcAd", "7cTdTh", "7cTdJc", "7cTdJd", "7cTdJh", "7cTdQc", "7cTdQd", "7cTdQh", "7cTdKc", "7cTdKd", "7cTdKh", "7cTdAc", "7cTdAd", "7cTdAh", "7cJcJd", "7cJcQc", "7cJcQd", "7cJcKc", "7cJcKd", "7cJcAc", "7cJcAd", "7cJdJh", "7cJdQc", "7cJdQd", "7cJdQh", "7cJdKc", "7cJdKd", "7cJdKh", "7cJdAc", "7cJdAd", "7cJdAh", "7cQcQd", "7cQcKc", "7cQcKd", "7cQcAc", "7cQcAd", "7cQdQh", "7cQdKc", "7cQdKd", "7cQdKh", "7cQdAc", "7cQdAd", "7cQdAh", "7cKcKd", "7cKcAc", "7cKcAd", "7cKdKh", "7cKdAc", "7cKdAd", "7cKdAh", "7cAcAd", "7cAdAh", "8c8d8h", "8c8d9d", "8c8d9h", "8c8dTd", "8c8dTh", "8c8dJd", "8c8dJh", "8c8dQd", "8c8dQh", "8c8dKd", "8c8dKh", "8c8dAd", "8c8dAh", "8c9c9d", "8c9cTc", "8c9cTd", "8c9cJc", "8c9cJd", "8c9cQc", "8c9cQd", "8c9cKc", "8c9cKd", "8c9cAc", "8c9cAd", "8c9d9h", "8c9dTc", "8c9dTd", "8c9dTh", "8c9dJc", "8c9dJd", "8c9dJh", "8c9dQc", "8c9dQd", "8c9dQh", "8c9dKc", "8c9dKd", "8c9dKh", "8c9dAc", "8c9dAd", "8c9dAh", "8cTcTd", "8cTcJc", "8cTcJd", "8cTcQc", "8cTcQd", "8cTcKc", "8cTcKd", "8cTcAc", "8cTcAd", "8cTdTh", "8cTdJc", "8cTdJd", "8cTdJh", "8cTdQc", "8cTdQd", "8cTdQh", "8cTdKc", "8cTdKd", "8cTdKh", "8cTdAc", "8cTdAd", "8cTdAh", "8cJcJd", "8cJcQc", "8cJcQd", "8cJcKc", "8cJcKd", "8cJcAc", "8cJcAd", "8cJdJh", "8cJdQc", "8cJdQd", "8cJdQh", "8cJdKc", "8cJdKd", "8cJdKh", "8cJdAc", "8cJdAd", "8cJdAh", "8cQcQd", "8cQcKc", "8cQcKd", "8cQcAc", "8cQcAd", "8cQdQh", "8cQdKc", "8cQdKd", "8cQdKh", "8cQdAc", "8cQdAd", "8cQdAh", "8cKcKd", "8cKcAc", "8cKcAd", "8cKdKh", "8cKdAc", "8cKdAd", "8cKdAh", "8cAcAd", "8cAdAh", "9c9d9h", "9c9dTd", "9c9dTh", "9c9dJd", "9c9dJh", "9c9dQd", "9c9dQh", "9c9dKd", "9c9dKh", "9c9dAd", "9c9dAh", "9cTcTd", "9cTcJc", "9cTcJd", "9cTcQc", "9cTcQd", "9cTcKc", "9cTcKd", "9cTcAc", "9cTcAd", "9cTdTh", "9cTdJc", "9cTdJd", "9cTdJh", "9cTdQc", "9cTdQd", "9cTdQh", "9cTdKc", "9cTdKd", "9cTdKh", "9cTdAc", "9cTdAd", "9cTdAh", "9cJcJd", "9cJcQc", "9cJcQd", "9cJcKc", "9cJcKd", "9cJcAc", "9cJcAd", "9cJdJh", "9cJdQc", "9cJdQd", "9cJdQh", "9cJdKc", "9cJdKd", "9cJdKh", "9cJdAc", "9cJdAd", "9cJdAh", "9cQcQd", "9cQcKc", "9cQcKd", "9cQcAc", "9cQcAd", "9cQdQh", "9cQdKc", "9cQdKd", "9cQdKh", "9cQdAc", "9cQdAd", "9cQdAh", "9cKcKd", "9cKcAc", "9cKcAd", "9cKdKh", "9cKdAc", "9cKdAd", "9cKdAh", "9cAcAd", "9cAdAh", "TcTdTh", "TcTdJd", "TcTdJh", "TcTdQd", "TcTdQh", "TcTdKd", "TcTdKh", "TcTdAd", "TcTdAh", "TcJcJd", "TcJcQc", "TcJcQd", "TcJcKc", "TcJcKd", "TcJcAc", "TcJcAd", "TcJdJh", "TcJdQc", "TcJdQd", "TcJdQh", "TcJdKc", "TcJdKd", "TcJdKh", "TcJdAc", "TcJdAd", "TcJdAh", "TcQcQd", "TcQcKc", "TcQcKd", "TcQcAc", "TcQcAd", "TcQdQh", "TcQdKc", "TcQdKd", "TcQdKh", "TcQdAc", "TcQdAd", "TcQdAh", "TcKcKd", "TcKcAc", "TcKcAd", "TcKdKh", "TcKdAc", "TcKdAd", "TcKdAh", "TcAcAd", "TcAdAh", "JcJdJh", "JcJdQd", "JcJdQh", "JcJdKd", "JcJdKh", "JcJdAd", "JcJdAh", "JcQcQd", "JcQcKc", "JcQcKd", "JcQcAc", "JcQcAd", "JcQdQh", "JcQdKc", "JcQdKd", "JcQdKh", "JcQdAc", "JcQdAd", "JcQdAh", "JcKcKd", "JcKcAc", "JcKcAd", "JcKdKh", "JcKdAc", "JcKdAd", "JcKdAh", "JcAcAd", "JcAdAh", "QcQdQh", "QcQdKd", "QcQdKh", "QcQdAd", "QcQdAh", "QcKcKd", "QcKcAc", "QcKcAd", "QcKdKh", "QcKdAc", "QcKdAd", "QcKdAh", "QcAcAd", "QcAdAh", "KcKdKh", "KcKdAd", "KcKdAh", "KcAcAd", "KcAdAh", "AcAdAh"};

double PREFLOP_EQUITY[169];
//double PREFLOP_NORMALIZED_GAINLOSS[169] = {};

double PREFLOP_CROSS_EQUITIES[169][169]; //hero, villain
double PREFLOP_COUNTER_EQUITIES[169][169]; //villain, hero
double PREFLOP_GAINLOSS[169][169]; //hero, villain

double PREFLOP_ADJUSTED_UTILITY[169][169]; //hero, villain

double PREFLOP_PRIOR_DENSITIES[169][169]; //hero, villain


//Compute the number of ways someone might have villain, given the player has hero.
int computePriorDensity(std::string villain, std::string hero = "XX") {
    bool villainPair = villain[0] == villain[1];
    bool heroPair = hero[0] == hero[1];
    bool villainSuited = !villainPair && villain[2] == 's';
    bool heroSuited = !heroPair && hero[2] == 's';

    if (villainPair) {
        if (heroPair) {
            if (villain[0] == hero[0]) {
                return 1; //ex: AA, 1 remaining AA
            }
            else {
                return 6; //ex: AA, 6 remaining KK
            }
        }
        else {
            if (villain[0] == hero[0] || villain[0] == hero[1]) {
                return 3; //ex: AK, 3 remaining AA
            }
            else {
                return 6; //ex: AK, 6 remaining QQ
            }
        }
    }
    else if (villainSuited) {
        if (heroPair) {
            if (villain[0] == hero[0] || villain[1] == hero[0]) {
                return 2; //ex: AA, 2 remaining AKs
            }
            else {
                return 4; //ex: AA, 4 remaining KQs
            }
        }
        else {
            if (villain[0] == hero[0] && villain[1] == hero[1]) {
                if (heroSuited) {
                    return 3; //ex: AKs, 3 remaining AKs
                }
                else {
                    return 2; //ex: AKo, 2 remaining AKs
                }
            }
            else if (villain[0] == hero[0] || villain[0] == hero[1]) {
                return 3; //ex: AK, 3 remaining KQs
            }
            else {
                return 4; //ex: AK, 4 remaining QJs
            }
        }
    }
    else {
        if (heroPair) {
            if (villain[0] == hero[0] || villain[1] == hero[0]) {
                return 6; //ex: AA, 6 remaining AKo
            }
            else {
                return 12; //ex: AA, 12 remaining KQo
            }
        }
        else {
            if (villain[0] == hero[0] && villain[1] == hero[1]) {
                if (heroSuited) {
                    return 6; //ex: AKs, 6 remaining AKo
                }
                else {
                    return 7; //ex: AKo, 7 remaining AKo
                }
            }
            else if (villain[0] == hero[0] || villain[0] == hero[1]) {
                return 9; //ex: AK, 9 remaining KQo
            }
            else {
                return 12; //ex: AK, 12 remaining QJo
            }
        }
    }
}

bool preflopEquityComparator(std::string first, std::string second) {
    return (PREFLOP_EQUITY[PREFLOP_HAND_ID[first]] > PREFLOP_EQUITY[PREFLOP_HAND_ID[second]]);
}

bool greaterComparator(double first, double second) {
    return first > second;
}

void initConstants() {
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            ALL_CARDS[index] = cards[i] + suits[j];
            index++;
        }
    }



    index = 0;
    for (int i = 0; i < 52; i++){
        for (int j = i + 1; j < 52; j++) {
            ALL_HANDS[index] = ALL_CARDS[i] + ALL_CARDS[j];
            index++;
        }
    }


    index = 0;
    for (int i = 0; i < 13; i++) {
        std::string pair = cards[i] + cards[i];
        PREFLOP_HANDS[index] = pair;
        PREFLOP_HAND_ID[pair] = index;
        index++;
        for (int j = i + 1; j < 13; j++) {
            std::string suited = cards[i] + cards[j] + "s";
            PREFLOP_HANDS[index] = suited;
            PREFLOP_HAND_ID[suited] = index;
            index++;
            std::string offsuit = cards[i] + cards[j] + "o";
            PREFLOP_HANDS[index] = offsuit;
            PREFLOP_HAND_ID[offsuit] = index;
            index++;
        }
    }
    std::ifstream fin;
    fin.open("data/preflop/random.txt");
    for (int i = 0; i < 169; i++) {
        std::string hand;
        double equity, dummy;
        fin >> hand >> equity >> dummy >> dummy >> dummy;
        PREFLOP_EQUITY[PREFLOP_HAND_ID[hand]] = equity;
    }
    fin.close();

    std::sort(PREFLOP_HANDS, PREFLOP_HANDS+169, preflopEquityComparator);
    std::sort(PREFLOP_EQUITY, PREFLOP_EQUITY+169, greaterComparator);
    for (int i = 0; i < 169; i++) {
        PREFLOP_HAND_ID[PREFLOP_HANDS[i]] = i;
    }

    //compute preflop densities
    for (int i = 0; i < 169; i++) {
        for (int j = 0; j < 169; j++) {
            PREFLOP_PRIOR_DENSITIES[i][j] = computePriorDensity(PREFLOP_HANDS[j], PREFLOP_HANDS[i]);
        }
        double rowsum = sum(PREFLOP_PRIOR_DENSITIES[i]);
        for (int j = 0; j < 169; j++) {
            PREFLOP_PRIOR_DENSITIES[i][j] *= (1000 / rowsum);
        }
    }

    return;

    //load cross equity and counter equity from file
    for (int i = 0; i < 169; i++) {
        std::string villain = PREFLOP_HANDS[i];
        fin.open("data/preflop/" + villain + ".txt");
        for (int j = 0; j < 169; j++) {
            std::string hero;
            double equity;
            double wins, ties, total;
            fin >> hero >> equity >> wins >> ties >> total;
            PREFLOP_CROSS_EQUITIES[PREFLOP_HAND_ID[hero]][i] = equity;
            PREFLOP_GAINLOSS[PREFLOP_HAND_ID[hero]][i] = 2 * equity - 1;
            PREFLOP_COUNTER_EQUITIES[i][PREFLOP_HAND_ID[hero]] = equity;
        }
        fin.close();
    }



    for (int i = 0; i < 169; i++) {
        for (int j = 0; j < 169; j++) {
            PREFLOP_ADJUSTED_UTILITY[i][j] = (PREFLOP_GAINLOSS[i][j] + (100.0 / 20000.0)) * PREFLOP_PRIOR_DENSITIES[i][j];
        }
    }
}

#endif