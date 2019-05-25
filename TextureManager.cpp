#include "TextureManager.h"
#include "Game.h"


SDL_Renderer* TextureManager::renderer = nullptr;

void TextureManager::init(SDL_Renderer* _renderer) {
	TextureManager::renderer = _renderer;
}

SDL_Texture* TextureManager::Load(std::string path) {
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = CreateTexture(tmpSurface);
	if (texture == NULL) {
		printf("Failed to load texture %s. Error: %s\n", path.c_str(), IMG_GetError());
	}
	SDL_FreeSurface(tmpSurface);
	return texture;
}

SDL_Texture* TextureManager::CreateTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	return texture;
}
