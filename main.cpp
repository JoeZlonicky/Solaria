#include <SDL.h>
#include <stdio.h>
#include "Game.h"

int main(int argc, char* argv[]) {
	Game game = Game("Solaria", 1280, 720);
	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}
	game.free();
	return 0;
}