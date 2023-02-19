#include "Board.h"
#include "Ship.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < 10; i++) {
        vector<int> temp;
        for (int j = 0; j < 10; j++) {
            temp.push_back(0);
        }
        boardArr.push_back(temp);
    }

    ships[1] = 5;
    ships[2] = 4;
    ships[3] = 3;
    ships[4] = 3;
    ships[5] = 2;    
}

void Board::placeShips() {
    for (int i = 1; i <= 5; i++) {
        bool placed = false;
        while (!placed) {
            int randCol = rand() % 10;
            int randRow = rand() % 10;
            int randDir = rand() % 4; // 0 = up, 1 = right, 2 = down, 3 = left
            bool placeFail = false;

            if (((randDir == 0) && (randRow < ships[i] - 1)) ||
                ((randDir == 1) && (randCol > 10 - ships[i])) ||
                ((randDir == 2) && (randRow > 10 - ships[i])) ||
                ((randDir == 3) && (randCol < ships[i] - 1))) {
                    continue;
                }
            
            if (randDir == 0) {
                for (int j = 0; j < ships[i]; j++) {
                    if (boardArr.at(randCol).at(randRow - j) != 0) {
                        placeFail = true;
                    }
                }
            }
            else if (randDir == 1) {
                for (int j = 0; j < ships[i]; j++) {
                    if (boardArr.at(randCol + j).at(randRow) != 0) {
                        placeFail = true;
                    }
                }
            }
            else if (randDir == 2) {
                for (int j = 0; j < ships[i]; j++) {
                    if (boardArr.at(randCol).at(randRow + j) != 0) {
                        placeFail = true;
                    }
                }
            }
            else if (randDir == 3) {
                for (int j = 0; j < ships[i]; j++) {
                    if (boardArr.at(randCol - j).at(randRow) != 0) {
                        placeFail = true;
                    }
                }
            }

            if (!placeFail) {
                if (randDir == 0) {
                    for (int j = 0; j < ships[i]; j++) {
                        boardArr[randCol][randRow - j] = i;
                    }
                }
                else if (randDir == 1) {
                    for (int j = 0; j < ships[i]; j++) {
                        boardArr[randCol + j][randRow] = i;
                    }
                }
                else if (randDir == 2) {
                    for (int j = 0; j < ships[i]; j++) {
                        boardArr[randCol][randRow + j] = i;
                    }
                }
                else if (randDir == 3) {
                    for (int j = 0; j < ships[i]; j++) {
                        boardArr[randCol - j][randRow] = i;
                    }
                }
                placed = true;
            }
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (boardArr[i][j] == 0) {cout << ".";}
            else if (boardArr[i][j] == -1) {cout << "X";}
            else {cout << boardArr[i][j];}
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int Board::playMove(pair<int, int> guess) {
    if (binary_search(guessedCells.begin(), guessedCells.end(), guess)) {
        throw invalid_argument("Cell has already been guessed");
    }

    int result = boardArr[guess.first][guess.second];
    boardArr[guess.first][guess.second] = -1;
    guessedCells.push_back(guess);

    for (auto row = boardArr.begin(); row != boardArr.end(); row++) {
        if (find(row->begin(), row->end(), result) != row->end()) {
            return result;
        }
    }
    return result + 10;
}
