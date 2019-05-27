#include "Game.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Game::Game(std::string title, int displayWidth, int displayHeight) {
	init();
	display = new Display(title, displayWidth, displayHeight);
	loadObjects();
}

Game::Game(std::string title, bool fullscreen){
	init();
	display = new Display(title, fullscreen);
	loadObjects();
}

void Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL Failed to initalize everything! SDL Error: %s\n", SDL_GetError());
	}
	if (TTF_Init() == -1) {
		printf("Failed to initialize TTF. Error: %s\n", TTF_GetError());
	}
	RandomGenerator::init();
}

void Game::loadObjects() {
	player = new Player("assets/player.png");
	player->setCenter(0, 0);
	sun = new Planet("assets/sun.png", 0, 0);
	sun->setCenter(0, 0);
	greenPlanet = new Planet("assets/greenPlanet.png", 0.0001, 800);
	redPlanet = new Planet("assets/redPlanet.png", -0.000075, 1200);
	rockPlanet = new Planet("assets/rockPlanet.png", -0.00005, 400);
	projectile = new Projectile("assets/enemy.png", player->getRotation(), player->getX(), player->getY());
	map = new Map(10000, 10000, display->getWidth(), display->getHeight());
	camera = new Camera(display->getWidth(), display->getHeight());
	camera->updateMap(map);
	xLabelPosition = new Label("0", "assets/upheavtt.ttf", 28, 255, 255, 255, 10, 0);
	zLabelPosition = new Label("0", "assets/upheavtt.ttf", 28, 255, 255, 255, 10, 30);
	asteroidHandler = new AsteroidHandler();
	asteroidHandler->addAsteroid(0, 0);
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
		case(SDL_KEYDOWN):
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
			else if (event.key.keysym.sym == SDLK_SPACE) {
				for (Asteroid* asteroid : asteroidHandler->getAsteroids()) {
					asteroid->hit();
				}
			}
		default:
			break;
		}
	}
}

void Game::update() {
	player->update();
	player->calculateRotation(display);
	//asteroids.push_back(Asteroid(0, 0));
	asteroidHandler->update();
	greenPlanet->update();
	redPlanet->update();
	rockPlanet->update();
	xLabelPosition->updateText("x: " + std::to_string(player->getCenterX()));
	zLabelPosition->updateText("z: " + std::to_string(player->getCenterY()));

}

void Game::render() {
	display->clear();
	camera->update(player);

	display->draw(map, camera);

	display->draw(greenPlanet, camera);
	display->draw(redPlanet, camera);
	display->draw(rockPlanet, camera);
	display->draw(sun, camera);
	display->draw(player, camera);
	asteroidHandler->drawAsteroids(display, camera);
	if (projectiles.empty() == false) {
		for (Projectile* projectile : projectiles) {
			display->draw(projectile, camera);
		}
	}
	display->draw(xLabelPosition);
	display->draw(zLabelPosition);
	display->drawCursor();

	display->update();
}

void Game::free() {
	display->free();
	greenPlanet->free();
	redPlanet->free();
	rockPlanet->free();
	sun->free();
	player->free();
	asteroidHandler->freeAsteroids();
	for (Projectile* projectile : projectiles) {
		projectile->free();
	}
	map->free();
	SDL_Quit();
}

void Game::addProjectile(Projectile projectileToAdd) {
	projectiles.push_back(&projectileToAdd);
}

bool Game::isRunning() {
	return running;
}
