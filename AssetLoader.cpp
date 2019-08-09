#include "AssetLoader.h"

#include <SDL_image.h>
#include "Game.h"

SDL_Renderer* AssetLoader::renderer = nullptr;
std::map<std::string, SDL_Texture*> AssetLoader::loadedTextures;
std::map<std::pair<std::string, int>, TTF_Font*> AssetLoader::loadedFonts;


// Set renderer
void AssetLoader::init(SDL_Renderer* _renderer) {
	AssetLoader::renderer = _renderer;
}

// Load a SDL_Texture from a file
SDL_Texture* AssetLoader::LoadTexture(std::string path) {
	if (loadedTextures.count(path) > 0) {
		return loadedTextures[path];
	}
	SDL_Texture* texture;
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	if (tmpSurface == nullptr) {
		printf("Failed to load image %s. Error: %s\n", path.c_str(), IMG_GetError());
		return nullptr;
	}
	texture = CreateTexture(tmpSurface);
	if (texture != nullptr) {
		loadedTextures[path] = texture;
	}
	SDL_FreeSurface(tmpSurface);
	return texture;
}

// Create a SDL_Texture from a surface
SDL_Texture* AssetLoader::CreateTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == nullptr) {
		printf("Failed to create texture from surface. Error: %s\n", SDL_GetError());
	}
	return texture;
}

// Create a SDL_Texture from text
SDL_Texture* AssetLoader::CreateTexture(std::string text, TTF_Font* font, SDL_Color color) {
	SDL_Texture* texture;
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surface == nullptr) {
		printf("Failed to create surface from font. Error: %s\n", TTF_GetError());
		return nullptr;
	}
	texture = CreateTexture(surface);
	SDL_FreeSurface(surface);
	return texture;
}

// Load a TTF_Font from a file
TTF_Font* AssetLoader::loadFont(std::string path, int size) {
	std::pair<std::string, int> key(path, size);
	if (loadedFonts.count(key) > 0) {
		return loadedFonts[key];
	}
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	if (font == nullptr) {
		printf("Failed to open font from %s. Error: %s\n", path.c_str(), TTF_GetError());
	}
	else {
		loadedFonts[key] = font;
	}
	return font;
}

// Free textures and font assets
void AssetLoader::freeLoadedAssets() {
	std::map<std::string, SDL_Texture*>::iterator textureIt;
	for (textureIt = loadedTextures.begin(); textureIt != loadedTextures.end(); ++textureIt) {
		SDL_DestroyTexture(textureIt->second);
	}

	std::map<std::pair<std::string, int>, TTF_Font*>::iterator fontIt;
	for (fontIt = loadedFonts.begin(); fontIt != loadedFonts.end(); ++fontIt) {
		TTF_CloseFont(fontIt->second);
	}
}