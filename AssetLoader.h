#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <map>


namespace AssetLoader {
	extern SDL_Renderer* renderer;
	extern std::map<std::string, SDL_Texture*> loadedTextures;
	void init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* LoadTexture(SDL_Surface* surface);
	TTF_Font* loadFont(std::string path, int size);
	void free();
}

