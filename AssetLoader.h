#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <map>
#include <string>
#include <utility>

namespace AssetLoader {
	extern SDL_Renderer* renderer;
	extern std::map<std::string, SDL_Texture*> loadedTextures;
	extern std::map<std::pair<std::string, int>, TTF_Font*> loadedFonts;

	void init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(std::string path);
	SDL_Texture* CreateTexture(SDL_Surface* surface);
	SDL_Texture* CreateTexture(std::string text, TTF_Font* font, SDL_Color color);
	TTF_Font* loadFont(std::string path, int size);
	void freeLoadedAssets();
}

