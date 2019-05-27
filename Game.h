#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "Display.h"
#include "Map.h"
#include "Sprite.h"
#include "Camera.h"
#include "Player.h"
#include "Planet.h"
#include "AsteroidHandler.h"
#include "Projectile.h"

class Game {
public:
	Game(std::string title, int width, int height);
	Game(std::string title, bool fullscreen);

	void init();
	void loadObjects();

	void handleEvents();
	void update();
	void render();
	void free();

	void addProjectile(Projectile projectileToAdd);

	bool isRunning();

private:
	Display* display = nullptr;
	bool running = true;
	std::string title;
	Player* player = nullptr;
	Planet* sun = nullptr;
	Planet* greenPlanet = nullptr;
	Planet* redPlanet = nullptr;
	Planet* rockPlanet = nullptr;
	Projectile* projectile = nullptr;
	Map* map = nullptr;
	Camera* camera = nullptr;
	Label* xLabelPosition = nullptr;
	Label* zLabelPosition = nullptr;
	AsteroidHandler* asteroidHandler = nullptr;
	std::vector<Projectile*> projectiles = std::vector<Projectile*>();
};
