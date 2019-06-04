#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <map>
#include <utility>


namespace AssetLoader {
	extern SDL_Renderer* renderer;
	extern std::map<std::string, SDL_Texture*> loadedTextures;
	extern std::map<std::pair<std::string, int>, TTF_Font*> loadedFonts;
	void init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* LoadTexture(SDL_Surface* surface);
	TTF_Font* loadFont(std::string path, int size);
	void free();
}

