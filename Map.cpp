#include "Map.h"
#include "AssetLoader.h"


Map::Map() {
	texture = AssetLoader::LoadTexture("assets/background.png");
	SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
}

void Map::free() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
}

SDL_Texture* Map::getTexture() {
	return texture;
}

int Map::getTextureWidth() {
	return textureWidth;
}

int Map::getTextureHeight() {
	return textureHeight;
}
