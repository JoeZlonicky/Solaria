#include "Display.h"

Display::Display(std::string title, int width, int height, bool fullscreen) : width(width), height(height), fullscreen(fullscreen) {
	int fullscreenFlag = 0;
	if (fullscreen) {
		fullscreenFlag = SDL_WINDOW_FULLSCREEN;
	}
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | fullscreenFlag);
	if (window == NULL) {
		printf("Failed to create window. Error: %s\n", SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == NULL) {
		printf("Failed to create renderer. Error: %s\n", SDL_GetError());
	}
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

void Display::update() {
	SDL_RenderPresent(renderer);
}


void Display::free() {
	SDL_DestroyWindow(window);
}
