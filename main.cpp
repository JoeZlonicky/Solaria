#include <SDL.h>
#include <stdio.h>
#include "Game.h"

int main(int argc, char* argv[]) {
	Game game = Game("Solaria", 1280, 720);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart{};
	int frameTime;

	while (game.isRunning()) {
		game.handleEvents();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game.free();
	return 0;
}