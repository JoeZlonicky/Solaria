#include "Game.h"
#include "TextureManager.h"


Game::Game(std::string title, int displayWidth, int displayHeight) {
	init();
	display = new Display(title, displayWidth, displayHeight);
	TextureManager::init(display->getRenderer());
	player = new Player("assets/grass.png", 32, 32);
	planet = new Planet("Earth", "assets/planet.png", 32, 32);
	map = new Map(10000, 10000, display->getWidth(), display->getHeight());
	camera = new Camera(display->getWidth(), display->getHeight());
	camera->updateMap(map);
}

Game::Game(std::string title, bool fullscreen){
	init();
	display = new Display(title, fullscreen);
	TextureManager::init(display->getRenderer());
	player = new Player("assets/grass.png", 32, 32);
	planet = new Planet("Earth", "assets/planet.png", 32, 32);
	map = new Map(1000, 1000, display->getWidth(), display->getHeight());
	camera = new Camera(display->getWidth(), display->getHeight());
	camera->updateMap(map);
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
	player->update();
}

void Game::render() {
	display->clear();
	camera->update(player);
	display->draw(map, camera);
	display->draw(planet, camera);
	display->draw(player, camera);
	display->update();
}

void Game::free() {
	display->free();
	planet->free();
	player->free();
	map->free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}