#include "Game.h"

Game::Game(){
	init("Test", false);
	
}

void Game::init(std::string title, bool fullscreen){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("SDL Failed to create the window! SDL Error: %s\n", SDL_GetError());
	}
	SDL_Delay(3000);
}

void Game::update(){
}

void Game::render(){
}

void Game::clean(){
	SDL_DestroyWindow(window);
}

void Game::loop() {
	while (isRunning) {
		/*
		Handle Events
		*/
	}
}
