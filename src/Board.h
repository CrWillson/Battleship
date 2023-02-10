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

private:
    int boardArr[10][10];
    map<int, int> ships;
};