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
    pair<int, int> move;
    bool valid = false;

    while (!valid) {
        try {
            move = getMovePair();
        }
        catch (invalid_argument e) {
            cout << e.what() << endl;
            continue;
        }
        valid = true;
    }
    
    return move;
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