#pragma once
#include <SDL.h>
#include <stdio.h>
class Game{
public:
	Game();

	void init();

	void update();
	void render();
	void clean();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

