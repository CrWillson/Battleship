//#include <ncurses.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Game mainGame;

	for (int i = 0; i < 5; i++) {
		mainGame.printBoards();
		mainGame.playMove();
	}
	mainGame.printBoards();

	return 0;
}
