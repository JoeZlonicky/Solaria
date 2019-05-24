#pragma once
#include <SDL.h>

class Map {
public:
	Map(int width, int height, int displayWidth, int displayHeight);

	void free();
	SDL_Texture* getTexture();
	
private:
	SDL_Texture* texture = nullptr;
	int width;
	int height;
	int displayWidth;
	int displayHeight;
};

