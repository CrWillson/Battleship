#include "Game.h"

using namespace std;

Game::Game() {
    playerBoard.placeShips();
    compBoard.placeShips();
}

void Game::printBoards() {
    compBoard.printBoard();
    playerBoard.printBoard();
}

pair<int, int> Game::getMove()
{
    string move;
    
    cout << "Enter your move: ";
    cin >> move;

    int col = (int)move[0] - 97;
    int row = stoi(move.substr(1,2)) - 1;
    
    return pair<int, int>(col, row);
}
