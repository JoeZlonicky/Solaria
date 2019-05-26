#pragma once
#include <SDL.h>
#include <string>
#include "Sprite.h"
#include "Label.h"
#include "Map.h"
#include "Camera.h"

class Display {
public:
	Display(std::string title, bool fullscreen);
	Display(std::string title, int width, int height);

	void clear();
	void update();
	void free();
	void setClearColor(Uint8 r, Uint8 g, Uint8 b);
	void draw(Sprite* sprite, Camera* camera);
	void draw(Sprite* sprite, Camera* camera, double angle, SDL_RendererFlip flip);
	void draw(Map* map, Camera* camera);
	void draw(Label* label);
	void drawCursor();
	void setIcon();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
	int getWidth();
	int getHeight();

private:
	void createRenderer();
	int* getScreenDimensions();
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* cursorTexture = nullptr;
	int cursorSize = 16;
	bool fullscreen = false;
	Uint8 clearR = 0;
	Uint8 clearG = 0;
	Uint8 clearB = 0;
	int width = 0;
	int height = 0;
};