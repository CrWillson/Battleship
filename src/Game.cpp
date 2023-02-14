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
            move = getMovePair();
        }
        catch (invalid_argument e) {
            cout << e.what() << endl;
            continue;
        }
        valid = true;
    }

}

pair<int, int> Game::getMovePair() {
    string moveStr;

    cout << "Enter your move: ";
    cin >> moveStr;

    if (moveStr.length() < 2 || moveStr.length() > 3) {
        throw invalid_argument("Invalid move");
    }
    
    int col = (int)tolower(moveStr[0]) - 97;
    if (col < 0 || col > 9) {
        throw invalid_argument("Out of range column");
    }

    int row = stoi(moveStr.substr(1, 2)) - 1;
    if (row < 0 || row > 9) {
        throw invalid_argument("Out of range row");
    }


    return pair<int, int>();
}