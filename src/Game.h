#pragma once

#include "Board.h"
#include <iostream>
#include <string>

class Board;
class Ship;
class Game {
public:
    Game();
    void printBoards();
    pair<int, int> getMove();

private:
    Board playerBoard;
    Board compBoard;

    pair<int, int> getMovePair();

};