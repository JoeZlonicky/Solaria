#include "Game.h"

Game::Game(){
	init();
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
}

void Game::init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}

	
}

void Game::update(){
}

void Game::render(){
}

void Game::clean(){
	SDL_DestroyWindow(window);
}
