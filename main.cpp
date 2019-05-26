#include <SDL.h>
#include <stdio.h>
#include "Game.h"

#define fps 60

int main(int argc, char* argv[]) {
	Game game = Game("Solaria", 1280, 720);

	Uint32 starting_tick;

	while (game.isRunning()) {
		starting_tick = SDL_GetTicks();
		game.handleEvents();
		game.update();
		game.render();

		if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
			SDL_Delay(1000/fps - (SDL_GetTicks() - starting_tick));
		}

	}
	game.free();
	return 0;
}