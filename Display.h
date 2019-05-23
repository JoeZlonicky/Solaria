#pragma once
#include <SDL.h>
#include <string>

class Display {
public:
	Display(std::string title, int width, int height, bool fullscreen);
	void clear();
	void update();
	void free();
	void setClearColor(Uint8 r, Uint8 g, Uint8 b);
	SDL_Renderer* getRenderer();

private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	int width;
	int height;
	bool fullscreen = false;
	Uint8 clearR = 0;
	Uint8 clearG = 0;
	Uint8 clearB = 0;
};