#pragma once
#include <string>
#include <vector>

#include "Display.h"
#include "Player.h"
#include "Map.h"
#include "Camera.h"
#include "UI.h"
#include "SpaceUI.h"
#include "EnemyMotherShip.h"

class Game {
public:
	Game(std::string title, int width, int height);
	Game(std::string title);

	void setup();
	void handleEvents();
	void update();
	void render();
	void free();

	bool isRunning();

private:
	Display display;
	Player player;
	EnemyMotherShip enemyMotherShip;
	Map map;
	Camera camera;
	SpaceUI spaceUI;
	SpaceUI* pausedUI = nullptr;
	bool running = true;
	bool paused = false;
};
