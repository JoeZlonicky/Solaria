#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


namespace AssetLoader {
	extern SDL_Renderer* renderer;
	void init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* LoadTexture(SDL_Surface* surface);
}

