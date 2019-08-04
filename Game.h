#pragma once
#include <string>
#include <vector>

#include "UIManager.h"
#include "Display.h"
#include "Player.h"
#include "Map.h"
#include "Camera.h"
#include "EnemyMotherShip.h"

class UIManager;

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
	Display* getDisplay();
	Player* getPlayer();
	Map* getMap();
	Camera* getCamera();
	UIManager* getUIManager();

private:
	Display display;
	Player player;
	EnemyMotherShip enemyMotherShip;
	Map map;
	Camera camera;
	UIManager uiManager;
	bool running = true;
};
