#pragma once
#include <SDL.h>

class Map {
public:
	Map();

	void free();
	SDL_Texture* getTexture();
	int getTextureWidth();
	int getTextureHeight();
	
private:
	SDL_Texture* texture = nullptr;
	int textureWidth;
	int textureHeight;
};

