#pragma once
#include <SDL.h>
#include <string>
#include "Sprite.h"

class Display {
public:
	Display(std::string title, bool fullscreen);
	Display(std::string title, int width, int height);

	void clear();
	void update();
	void free();
	void setClearColor(Uint8 r, Uint8 g, Uint8 b);
	void draw(Sprite* sprite);
	SDL_Renderer* getRenderer();

private:
	void createRenderer();
	int* getScreenDimensions();
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	bool fullscreen = false;
	Uint8 clearR = 0;
	Uint8 clearG = 0;
	Uint8 clearB = 0;
};