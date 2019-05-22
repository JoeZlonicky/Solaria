#include "Game.h"

Game::Game() {
	init("Test", false);

}

void Game::init(std::string title, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
}

void Game::update() {
}

void Game::render() {
}

void Game::clean() {
	SDL_DestroyWindow(window);
}

void Game::loop() {
	while (isRunning) {
		/*
		Handle Events
		*/
	}
}
