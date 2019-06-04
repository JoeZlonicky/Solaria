#include "AssetLoader.h"
#include "Game.h"

SDL_Renderer* AssetLoader::renderer = nullptr;
std::map<std::string, SDL_Texture*> AssetLoader::loadedTextures;
std::map<std::pair<std::string, int>, TTF_Font*> AssetLoader::loadedFonts;

void AssetLoader::init(SDL_Renderer* _renderer) {
	AssetLoader::renderer = _renderer;
}

SDL_Texture* AssetLoader::LoadTexture(std::string path) {
	SDL_Texture* texture;
	if (loadedTextures.count(path) > 0) {
		texture = loadedTextures[path];
	}
	else {
		SDL_Surface* tmpSurface = IMG_Load(path.c_str());
		texture = LoadTexture(tmpSurface);
		if (texture == NULL) {
			printf("Failed to load texture %s. Error: %s\n", path.c_str(), IMG_GetError());
		}
		else {
			loadedTextures[path] = texture;
		}
		SDL_FreeSurface(tmpSurface);
	}
	return texture;
}

SDL_Texture* AssetLoader::LoadTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		printf("Failed to create texture from surface. Error: %s\n", SDL_GetError());
	}
	return texture;
}

TTF_Font* AssetLoader::loadFont(std::string path, int size) {
	std::pair<std::string, int> key(path, size);
	if (loadedFonts.count(key) > 0) {
		return loadedFonts[key];
	}
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	if (font == NULL) {
		printf("Failed to open font from %s. Error: %s\n", path.c_str(), TTF_GetError());
	}
	else {
		loadedFonts[key] = font;
	}
	return font;
}

void AssetLoader::free() {
	std::map<std::string, SDL_Texture*>::iterator textureIt;
	for (textureIt = loadedTextures.begin(); textureIt != loadedTextures.end(); ++textureIt) {
		SDL_DestroyTexture(textureIt->second);
	}

	std::map<std::pair<std::string, int>, TTF_Font*>::iterator fontIt;
	for (fontIt = loadedFonts.begin(); fontIt != loadedFonts.end(); ++fontIt) {
		TTF_CloseFont(fontIt->second);
	}
}
