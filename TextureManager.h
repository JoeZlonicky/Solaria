#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


namespace TextureManager {
	extern SDL_Renderer* renderer;
	void init(SDL_Renderer* renderer);
	SDL_Texture* Load(std::string path);
	void Draw(SDL_Texture* texture, SDL_Rect *srcRect, SDL_Rect *destRect);
}

