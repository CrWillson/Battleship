#include <ncurses.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	cout << "Hello World" << endl;
	Game mainGame;

	mainGame.compBoard.printBoard();
	mainGame.playerBoard.printBoard();

	return 0;
}
