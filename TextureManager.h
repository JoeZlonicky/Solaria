#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace TextureManager {

	SDL_Texture* LoadTexture(std::string path);

	void Draw(SDL_Texture* texture, SDL_Rect *srcRect, SDL_Rect *destRect);


}

