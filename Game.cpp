#include "Game.h"

Game::Game(std::string title, bool fullscreen) {
	display = new Display(title, 1280, 720, fullscreen);
	init();
	loop();
}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
}

void Game::update() {
}

void Game::render() {
}

void Game::clean() {
	display->free();
}

void Game::loop() {
	while (isRunning) {
		/*
		Handle Events
		*/
	}
}
