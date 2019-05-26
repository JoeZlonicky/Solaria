#include "AssetLoader.h"
#include "Game.h"


SDL_Renderer* AssetLoader::renderer = nullptr;

void AssetLoader::init(SDL_Renderer* _renderer) {
	AssetLoader::renderer = _renderer;
}

SDL_Texture* AssetLoader::LoadTexture(std::string path) {
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = LoadTexture(tmpSurface);
	if (texture == NULL) {
		printf("Failed to load texture %s. Error: %s\n", path.c_str(), IMG_GetError());
	}
	SDL_FreeSurface(tmpSurface);
	return texture;
}

SDL_Texture* AssetLoader::LoadTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	return texture;
}
