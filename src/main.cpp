//#include <ncurses.h>
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	Game mainGame;
	pair<int, int> move = mainGame.getMove();
	mainGame.printBoards();

	return 0;
}
