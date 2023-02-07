#include "Board.h"
#include "Ship.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            boardArr[i][j] = 0;
        }
    }

    Ship aircraft(0, 5);
    Ship battleship(1, 4);
    Ship cruiser(2, 3);
    Ship submarine(3, 3);
    Ship destroyer(4, 2);

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

            randDir = 0;

            if (((randDir == 0) && (randRow < ships[i] - 1)) ||
                ((randDir == 1) && (randCol > 10 - ships[i])) ||
                ((randDir == 2) && (randRow > 10 - ships[i])) ||
                ((randDir == 3) && (randCol < ships[i] - 1))) {
                    continue;
                }
            else {
                if (randDir == 0) {
                    for (int j = 0; j < ships[i]; j++) {
                        boardArr[randCol][randRow - j] = i;
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
            cout << boardArr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
