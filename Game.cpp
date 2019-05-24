#include "Game.h"
#include "TextureManager.h"

Game::Game(std::string title, int displayWidth, int displayHeight) {
	init();
	display = new Display(title, displayWidth, displayHeight);
	TextureManager::init(display->getRenderer());
	player = TextureManager::Load("grass.png");
}

Game::Game(std::string title, bool fullscreen){
	init();
	display = new Display(title, fullscreen);
	TextureManager::init(display->getRenderer());
	player = TextureManager::Load("grass.png");
}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case(SDL_QUIT):
			running = false;
			break;
		default:
			break;
		}
	}
}

void Game::update() {
}

void Game::render() {
	display->clear();
	TextureManager::Draw(player, NULL, NULL);
	display->update();
}

void Game::free() {
	display->free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}