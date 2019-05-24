#pragma once
#include <SDL.h>

class Map {
public:
	Map(int width, int height, int displayWidth, int displayHeight);

	void free();
	SDL_Texture* getTexture();
	int getWidth();
	int getHeight();
	int getTextureWidth();
	int getTextureHeight();
	
private:
	SDL_Texture* texture = nullptr;
	int textureWidth = 0;
	int textureHeight = 0;
	int width;
	int height;
	int displayWidth;
	int displayHeight;
};

