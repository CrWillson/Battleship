#include "Game.h"

using namespace std;

Game::Game() {
    playerBoard.placeShips();
    compBoard.placeShips();
    playerTurn = true;
}

void Game::printBoards() {
    compBoard.printBoard();
    playerBoard.printBoard();
}

void Game::playMove()
{
    pair<int, int> move;
    bool valid = false;

    while (!valid) {
        try {
            // change to get the move from either the comp or player board
            compBoard.playMove(playerBoard.getMove());
        }
        catch (invalid_argument e) {
            cout << e.what() << endl;
            continue;
        }
        valid = true;
    }

}