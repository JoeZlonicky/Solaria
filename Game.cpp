#include "Game.h"
#include "TextureManager.h"


Game::Game(std::string title, int displayWidth, int displayHeight) {
	init();
	display = new Display(title, displayWidth, displayHeight);
	TextureManager::init(display->getRenderer());
	loadObjects();
}

Game::Game(std::string title, bool fullscreen){
	init();
	display = new Display(title, fullscreen);
	TextureManager::init(display->getRenderer());
	loadObjects();
}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
}

void Game::loadObjects() {
	player = new Player("assets/player.png");
	player->setCenter(0, 0);

	sun = new Planet("assets/sun.png", 0, 0);
	sun->setCenter(0, 0);

	earth = new Planet("assets/planet.png", 0.0001, 400);

	map = new Map(10000, 10000, display->getWidth(), display->getHeight());

	camera = new Camera(display->getWidth(), display->getHeight());
	camera->updateMap(map);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case(SDL_QUIT):
			running = false;
			break;
		case(SDL_MOUSEMOTION):
			SDL_GetMouseState(&xMouse, &yMouse);
		default:
			break;
		}
	}
}

void Game::update() {
	player->update();
	earth->update();
	double delta_y = player->getCenterY() - yMouse;
	double delta_x = player->getCenterX() - xMouse;
	angle_deg = (atan2(delta_y, delta_x) * 180.0000) / 3.1416;
	printf("player x: %f player y: %f\n", player->getX(), player->getY());
}

void Game::render() {
	display->clear();
	camera->update(player);
	display->draw(map, camera);
	display->draw(earth, camera);
	display->draw(sun, camera);
	display->draw(player, camera, angle_deg, SDL_FLIP_NONE);
	display->update();
}

void Game::free() {
	display->free();
	earth->free();
	sun->free();
	player->free();
	map->free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}