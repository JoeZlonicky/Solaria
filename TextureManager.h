#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


namespace TextureManager {
	extern SDL_Renderer* renderer;
	void init(SDL_Renderer* renderer);
	SDL_Texture* Load(std::string path);
	SDL_Texture* CreateTexture(SDL_Surface* surface);
}

