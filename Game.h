#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>
class Game{
public:
	Game();

	void init(std::string title, bool fullscreen);

	void update();
	void render();
	void clean();
	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;

	void loop();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
};

