#include "Game.h"
#include "TextureManager.h"

Game::Game(std::string title, int displayWidth, int displayHeight) {
	init();
	display = new Display(title, displayWidth, displayHeight);
	TextureManager::init(display->getRenderer());
	player = new Sprite("assets/grass.png", 32, 32);
	map = new Map(1000, 1000, display->getWidth(), display->getHeight());
}

Game::Game(std::string title, bool fullscreen){
	init();
	display = new Display(title, fullscreen);
	TextureManager::init(display->getRenderer());
	player = new Sprite("assets/grass.png", 32, 32);
	map = new Map(1000, 1000, display->getWidth(), display->getHeight());
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
	player->moveX(1.5);
}

void Game::render() {
	display->clear();
	display->draw(map);
	display->draw(player);
	display->update();
}

void Game::free() {
	display->free();
	player->free();
	map->free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}