#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Display.h"

class Game {
public:
	Game(std::string title, int width, int height);
	Game(std::string title, bool fullscreen);

	void init();

	void handleEvents();
	void update();
	void render();
	void free();

	bool isRunning();

private:
	Display* display = nullptr;
	bool running = true;
	std::string title;
	Sprite* player = nullptr;
	Map* map = nullptr;
};

