#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>


namespace AssetLoader {
	extern SDL_Renderer* renderer;
	void init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* LoadTexture(SDL_Surface* surface);
	TTF_Font* loadFont(std::string path, int size);
}

