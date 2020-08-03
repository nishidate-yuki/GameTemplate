#include <iostream>
#include <memory>

#include "Game.h"

int main(int argc, char** argv)
{
	std::cout << "Started\n";
	auto game = std::make_shared<Game>();
	if (game->Initialize()) {
		game->RunLoop();
	}
	return 0;
}