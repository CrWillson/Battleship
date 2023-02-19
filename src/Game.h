#pragma once

#include "PlayerBoard.h"
#include "CompBoard.h"
#include <iostream>
#include <string>

class Game {
public:
    Game();
    void printBoards();
    void playMove();

private:
    PlayerBoard playerBoard;
    CompBoard compBoard;
    bool playerTurn;

};