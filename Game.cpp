#include "Game.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"
#include "SDL_image.h"
#include "SpaceUI.h"


// Start game with a window of specified size
Game::Game(std::string title, int displayWidth, int displayHeight) : display(title, displayWidth, displayHeight),
		camera(&display), map(&player), enemyMotherShip("assets/mothership.png", 100, 100, 100, 1.75, 10.0, &player) {
	setup();
}

// Start game with fullscreen display
Game::Game(std::string title) : display(title),
		camera(&display), map(&player), enemyMotherShip("assets/mothership.png", 100, 100, 100, 1.75, 10.0, &player){
	setup();
}

// Set intial state
void Game::setup() {
	player.setCenter(0, 0);
	uiManager.addLayer(new SpaceUI(this));
}

// Handle SDL events
void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		switch (event.type) {
		case(SDL_MOUSEMOTION):
			if (uiManager.pauseGame()) continue;
			int x, y;
			SDL_GetMouseState(&x, &y);
			player.updateMousePosition(x, y);
			break;
		case(SDL_MOUSEBUTTONDOWN):
			if (uiManager.pauseGame()) continue;
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
		uiManager.getFocusedLayer()->handleEvent(event);
	}
}

// Update state of game
void Game::update() {
	if (!uiManager.pauseGame()) {
		player.update();
		player.calculateRotation(&display);
		enemyMotherShip.update(map.getEnemyFighters());
		map.update();
	}
	uiManager.update();
}

// Draw game to display
void Game::render() {
	display.clear();
	camera.update(&player);

	display.draw(&map, &camera);
	display.draw(&player, &camera);
	display.draw(&enemyMotherShip, &camera);
	uiManager.draw();
	display.drawCursor();

	display.update();
}

// Free all resources and exit SDL
void Game::free() {
	AssetLoader::freeLoadedAssets();
	display.free();
	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
}

bool Game::isRunning() {
	return running;
}

Display* Game::getDisplay() {
	return &display;
}

Player* Game::getPlayer() {
	return &player;
}

Map* Game::getMap() {
	return &map;
}

Camera* Game::getCamera() {
	return &camera;
}

UIManager* Game::getUIManager() {
	return &uiManager;
}
