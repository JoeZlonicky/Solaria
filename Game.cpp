#include "Game.h"
#include "TextureManager.h"

Game::Game(std::string title, bool fullscreen) {
	init();
	display = new Display(title, 1280, 720, fullscreen);
	loop();
}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
	SDL_Texture* player = TextureManager::LoadTexture("grass.png");
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case(SDL_QUIT):
			isRunning = false;
			break;
		}
	}
}

void Game::update() {
}

void Game::render() {
	TextureManager::Draw(player, NULL, NULL);
}

void Game::clean() {
	display->free();
}

void Game::loop() {
	while (isRunning) {
		handleEvents();
		update();
		display->clear();
		render();
		display->update();
	}
}
