#include "Game.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Game::Game(std::string title, int displayWidth, int displayHeight) : display(title, displayWidth, displayHeight),
		camera(&display), xPositionLabel("0", "assets/upheavtt.ttf", 28),
		zPositionLabel("0", "assets/upheavtt.ttf", 28) {
	setup();
}

Game::Game(std::string title, bool fullscreen) : display(title, fullscreen),
		camera(&display), xPositionLabel("0", "assets/upheavtt.ttf", 28),
		zPositionLabel("0", "assets/upheavtt.ttf", 28) {
	setup();
}

void Game::setup() {
	player.setCenter(0, 0);
	xPositionLabel.setPosition(10, 6);
	zPositionLabel.setPosition(10, 32);
	planets.push_back(Planet("assets/sun.png", 0, 0));
	planets.push_back(Planet("assets/rockPlanet.png", 0.00005, 400));
	planets.push_back(Planet("assets/greenPlanet.png", 0.0001, 800));
	planets.push_back(Planet("assets/redPlanet.png", 0.000075, 1200));
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
				player.fireProjectile(projectiles);
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
	for (int i = 0; i < asteroids.size(); ++i) {
		//asteroids.at(i).update();
		if (asteroids.at(i).shouldDestroy()) {
			//asteroids.at(i).destroy(&asteroids);
			asteroids.erase(asteroids.begin());
		}
	}
	for (Projectile& projectile : projectiles) {
		projectile.update();
	}
	for (Planet &planet : planets) {
		planet.update();
	}
	
	xPositionLabel.updateText("x: " + std::to_string(player.getCenterX()));
	zPositionLabel.updateText("z: " + std::to_string(player.getCenterY()));
	

}

void Game::render() {
	display.clear();
	camera.update(&player);

	display.draw(&map, &camera);
	for (Planet planet : planets) {
		display.draw(&planet, &camera);
	}
	display.draw(&player, &camera);
	for (Asteroid asteroid : asteroids) {
		display.draw(&asteroid, &camera);
	}
	for (Projectile projectile : projectiles) {
		display.draw(&projectile, &camera);
	}
	display.draw(&xPositionLabel);
	display.draw(&zPositionLabel);
	display.drawCursor();

	display.update();
}

void Game::free() {
	for (Asteroid& asteroid : asteroids) {
		asteroid.free();
	}
	for (Planet &planet : planets) {
		planet.free();
	}
	for (Projectile &projectile : projectiles) {
		projectile.free();
	}
	player.free();
	map.free();
	display.free();
	SDL_Quit();
}

bool Game::isRunning() {
	return running;
}
