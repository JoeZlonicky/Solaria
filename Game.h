#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Display.h"

class Game {
public:
	Game(std::string title, bool fullscreen);

	void init();

	void handleEvents();
	void update();
	void render();
	void clean();

	void loop();

private:
	Display* display;
	bool isRunning = true;
	SDL_Texture* player;
};

