#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include "RandomGenerator.h"

bool init();

int main(int argc, char* argv[]) {
	if (!init()) {
		return 1;
	}

	Game game("Solaria", 1280, 720);
	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();
	}
	game.free();
	return 0;
}

bool init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything. Error: %s\n", SDL_GetError());
		return false;
	}
	if (TTF_Init() == -1) {
		printf("Failed to initialize TTF. Error: %s\n", TTF_GetError());
		return false;
	}
	RandomGenerator::init();
	return true;
}