#include "Game.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Game::Game(std::string title, int displayWidth, int displayHeight) : display(title, displayWidth, displayHeight),
		camera(&display), map(&player), spaceUI(&display), enemyMotherShip("assets/mothership.png", 100, 100, 100, 1.75, 10.0, &player) {
	setup();
}

Game::Game(std::string title, bool fullscreen) : display(title, fullscreen),
		camera(&display), map(&player), spaceUI(&display), enemyMotherShip("assets/mothership.png", 100, 100, 100, 1.75, 10.0, &player){
	setup();
}

void Game::setup() {
	player.setCenter(0, 0);
	camera.setMap(&map);
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
			player.setMouseCoords(x, y);
			break;
		case(SDL_MOUSEBUTTONDOWN):
			if (event.button.button == SDL_BUTTON_LEFT) {
				player.fireProjectile(map.getProjectiles(), 1);
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				player.fireProjectile(map.getProjectiles(), 3);
			}
			break;
		case(SDL_KEYDOWN):
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	player.update();
	player.calculateRotation(&display);
	enemyMotherShip.update(map.getEnemyFighters());
	map.update();
	spaceUI.hidePlanetName();
	for (Planet planet : *map.getPlanets()) {
		if (player.collides(planet)) {
			spaceUI.displayPlanetName(planet.getName());
		}
	}
	spaceUI.update(&player);
}

void Game::render() {
	display.clear();
	camera.update(&player);

	display.draw(&map, &camera);
	display.draw(&player, &camera);

	display.draw(&enemyMotherShip, &camera);

	
	spaceUI.draw(&display);
	display.drawCursor();

	display.update();
}

void Game::free() {
	AssetLoader::free();
	display.free();
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
}

bool Game::isRunning() {
	return running;
}
