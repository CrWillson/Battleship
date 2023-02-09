#pragma once

#include "Board.h"

class Board;
class Ship;
class Game {
public:
    Game();
    void printBoards();

private:
    Board playerBoard;
    Board compBoard;

};