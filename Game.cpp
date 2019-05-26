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
	if (TTF_Init() == -1) {
		printf("Failed to initialize TTF. Error: %s\n", TTF_GetError());
	}
}

void Game::loadObjects() {
	player = new Player("assets/player.png");
	player->setCenter(0, 0);
	sun = new Planet("assets/sun.png", 0, 0);
	sun->setCenter(0, 0);
	greenPlanet = new Planet("assets/greenPlanet.png", 0.0001, 800);
	redPlanet = new Planet("assets/redPlanet.png", -0.000075, 1200);
	rockPlanet = new Planet("assets/rockPlanet.png", -0.00005, 400);
	map = new Map(10000, 10000, display->getWidth(), display->getHeight());
	camera = new Camera(display->getWidth(), display->getHeight());
	camera->updateMap(map);
	xLabelPosition = new Label("0", "assets/upheavtt.ttf", 28, 255, 255, 255, 10, 0);
	zLabelPosition = new Label("0", "assets/upheavtt.ttf", 28, 255, 255, 255, 10, 30);
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case(SDL_QUIT):
			running = false;
			break;
		case(SDL_MOUSEMOTION):
			int x, y;
			SDL_GetMouseState(&x, &y);
			player->setMouseCoords(x, y);
		default:
			break;
		}
	}
}

void Game::update() {
	player->update();
	greenPlanet->update();
	redPlanet->update();
	rockPlanet->update();
	xLabelPosition->updateText("x: " + std::to_string(player->getCenterX()));
	zLabelPosition->updateText("z: " + std::to_string(player->getCenterY()));
	player->calculateRotation(display);

	
}

void Game::render() {
	display->clear();
	camera->update(player);
	display->draw(map, camera);
	display->draw(greenPlanet, camera);
	display->draw(redPlanet, camera);
	display->draw(rockPlanet, camera);
	display->draw(sun, camera);
	display->draw(player, camera, player->getAngle(), SDL_FLIP_NONE);
	display->draw(xLabelPosition);
	display->draw(zLabelPosition);
	display->update();
}

void Game::free() {
	display->free();
	greenPlanet->free();
	redPlanet->free();
	rockPlanet->free();
	sun->free();
	player->free();
	map->free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}