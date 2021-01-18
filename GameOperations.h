#ifndef GAMEOPERATIONS_H
#define GAMEOPERATIONS_H
#include <vector>
#include <iostream>
#include <string>
#include "Gamer.h"

using namespace std;

void showBoard(vector<vector<char>> matrix);

bool overflowedBoard(vector<vector<char>> matrix);

bool endGame(vector<vector<char>> matrix, vector<Gamer> v);

void fillBoard(vector<vector<char>> matrix, vector<Gamer> v);

void newGame(vector<vector<char>> matrix, vector<Gamer> v);

#endif