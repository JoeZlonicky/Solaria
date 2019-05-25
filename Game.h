#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Display.h"
#include "Map.h"
#include "Sprite.h"
#include "Camera.h"
#include "Player.h"
#include "Planet.h"

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

	bool isRunning();

private:
	Display* display = nullptr;
	bool running = true;
	std::string title;
	Player* player = nullptr;
	Planet* sun = nullptr;
	Planet* earth = nullptr;
	Map* map = nullptr;
	Camera* camera = nullptr;
	Label* xLabelPosition = nullptr;
	Label* zLabelPosition = nullptr;
};
