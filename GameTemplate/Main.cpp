#include <iostream>

#include "Game.h"

int main(int argc, char** argv)
{
	std::cout << "Started\n";
	Game game;
	if (game.Initialize()) {
		game.RunLoop();
	}
	return 0;
}