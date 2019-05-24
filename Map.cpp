#include "Map.h"
#include "TextureManager.h"


Map::Map(int width, int height, int displayWidth, int displayHeight) : width(width), height(height), 
		displayWidth(displayWidth), displayHeight(displayHeight) {
	texture = TextureManager::Load("assets/background.png");
}

void Map::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

SDL_Texture* Map::getTexture() {
	return texture;
}
