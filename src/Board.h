#pragma once

#include "Ship.h"
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

class Ship;
class Board {
public:
    Board();
    void placeShips();
    void printBoard();
    int playMove(pair<int, int>);

private:
    vector<vector<int>> boardArr;
    vector<pair<int, int>> guessedCells;
    map<int, int> ships;
};