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
	void setup();
	bool isRunning();

	void handleEvents();
	void update();
	void render();
	void free();

private:
	Display display;
	Player player;
	Map map;
	Camera camera;
	Label xLabelPosition;
	Label zLabelPosition;
	std::vector<Planet> planets;
	std::vector<Projectile> projectiles;
	std::vector<Asteroid> asteroids;
	bool running = true;
	
};
