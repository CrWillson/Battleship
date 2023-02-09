#include "Game.h"

Game::Game() {
    playerBoard.placeShips();
    compBoard.placeShips();
}

void Game::printBoards() {
    compBoard.printBoard();
    playerBoard.printBoard();
}
