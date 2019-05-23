#include "TextureManager.h"
#include "Game.h"


SDL_Renderer* TextureManager::renderer = nullptr;

void TextureManager::init(SDL_Renderer* _renderer) {
	TextureManager::renderer = _renderer;
}

SDL_Texture* TextureManager::Load(std::string path)
{
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	if (texture == NULL) {
		printf("Failed to load texture %s. Error: %s\n", path.c_str(), IMG_GetError());
	}
	SDL_FreeSurface(tmpSurface);
	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect *srcRect, SDL_Rect *destRect)
{
	SDL_Rect src = { 0, 0, 32, 32 };
	SDL_Rect dest = { 100, 100, 32, 32 };
	SDL_RenderCopy(renderer, texture, &src, &dest);
}
