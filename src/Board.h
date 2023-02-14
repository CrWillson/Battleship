#pragma once

#include "Ship.h"
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Ship;
class Board {
public:
    Board();
    void placeShips();
    void printBoard();
    virtual pair<int, int> getMove();

private:
    vector<vector<int>> boardArr;
    vector<pair<int, int>> guessedCells;
    map<int, int> ships;
};