#include "Game.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Game::Game(std::string title, int displayWidth, int displayHeight) : display(title, displayWidth, displayHeight),
		camera(&display), xPositionLabel("0", "assets/upheavtt.ttf", 28),
		zPositionLabel("0", "assets/upheavtt.ttf", 28), map(&player) {
	setup();
}

Game::Game(std::string title, bool fullscreen) : display(title, fullscreen),
		camera(&display), xPositionLabel("0", "assets/upheavtt.ttf", 28),
		zPositionLabel("0", "assets/upheavtt.ttf", 28), map(&player) {
	setup();
}

void Game::setup() {
	player.setCenter(0, 0);
	xPositionLabel.setPosition(10, 6);
	zPositionLabel.setPosition(10, 32);
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
		case(SDL_MOUSEBUTTONUP):
			if (event.button.button == SDL_BUTTON_LEFT) {
				player.fireProjectile(map.getProjectiles());
			}
		case(SDL_KEYDOWN):
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		default:
			break;
		}
	}
}

void Game::update() {
	player.update();
	player.calculateRotation(&display);
	map.update();
	
	xPositionLabel.updateText("x: " + std::to_string(player.getCenterX()));
	zPositionLabel.updateText("z: " + std::to_string(player.getCenterY()));
}

void Game::render() {
	display.clear();
	camera.update(&player);

	display.draw(&map, &camera);
	display.draw(&player, &camera);
	
	display.draw(&xPositionLabel);
	display.draw(&zPositionLabel);
	display.drawCursor();

	display.update();
}

void Game::free() {
	player.free();
	map.free();
	display.free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
