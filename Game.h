#pragma once
#include <string>
#include <vector>
#include "Display.h"
#include "Player.h"
#include "Map.h"
#include "Camera.h"
#include "Label.h"
#include "Planet.h"
#include "Projectile.h"
#include "Asteroid.h"

class Game {
public:
	Game(std::string title, int width, int height);
	Game(std::string title, bool fullscreen);

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
	Label xPositionLabel;
	Label zPositionLabel;
	std::vector<Projectile> projectiles;
	bool running = true;

};
