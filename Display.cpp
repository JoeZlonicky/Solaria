#include "Display.h"

Display::Display(std::string title, bool fullscreen) {
	int* dimensions = getScreenDimensions();
	width = dimensions[0];
	height = dimensions[1];

	int fullscreenFlag = 0;
	if (fullscreen) {
		fullscreenFlag = SDL_WINDOW_FULLSCREEN;
	}
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_SHOWN | fullscreenFlag);
	if (window == NULL) {
		printf("Failed to create window. Error: %s\n", SDL_GetError());
	}
	createRenderer();
}

Display::Display(std::string title, int width, int height) : width(width), height(height) {
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Failed to create window. Error: %s\n", SDL_GetError());
	}
	createRenderer();
}

void Display::createRenderer() {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Failed to create renderer. Error: %s\n", SDL_GetError());
	}
}

int* Display::getScreenDimensions() {
	SDL_DisplayMode displayMode;
	int dimensions[2];
	if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
		printf("Failed to get display mode. Error: %s\n", SDL_GetError());
	}
	else {
		dimensions[0] = displayMode.w;
		dimensions[1] = displayMode.h;
	}
	return dimensions;
}

void Display::clear() {
	SDL_SetRenderDrawColor(renderer, clearR, clearG, clearB, 255);
	SDL_RenderClear(renderer);
}

void Display::setClearColor(Uint8 r, Uint8 g, Uint8 b) {
	clearR = r;
	clearG = g;
	clearB = b;
}

void Display::draw(Sprite* sprite, Camera* camera) {
	SDL_Rect rect = camera->apply(sprite->getRect());
	SDL_RenderCopy(renderer, sprite->getTexture(), NULL, &rect);
}

void Display::draw(Map* map, Camera* camera) {
	SDL_Rect mapRect = { 0, 0, map->getWidth(), map->getHeight() };
	SDL_Rect rect = camera->apply(mapRect);
	SDL_RenderCopy(renderer, map->getTexture(), NULL, &rect);
}

SDL_Renderer* Display::getRenderer() {
	return renderer;
}

int Display::getWidth() {
	return width;
}

int Display::getHeight() {
	return height;
}

void Display::update() {
	SDL_RenderPresent(renderer);
}

void Display::free() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
