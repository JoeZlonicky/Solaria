#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(std::string path)
{
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect)
{
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}
