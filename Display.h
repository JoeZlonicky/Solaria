#pragma once

#include <SDL.h>
#include <string>
#include "Sprite.h"
#include "Map.h"
#include "Camera.h"

class Map;

class Display {
public:
	Display(std::string title);
	Display(std::string title, int windowWidth, int windowHeight);

	void init(std::string title, int windowWidth, int windowHeight, int fullscreenFlag);
	void clear();
	void update();
	void free();
	void draw(Sprite* sprite, Camera* camera = nullptr);
	void drawCollider(Sprite* sprite, Camera* camera = nullptr);
	void draw(Map* map, Camera* camera);
	void drawCursor();

	void setClearColor(Uint8 r, Uint8 g, Uint8 b);
	void setIcon();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();
	int getWidth();
	int getHeight();
	int getWindowWidth();
	int getWindowHeight();

private:
	void createRenderer();

	const int cursorSize = 20;
	const int fps = 120;
	const int resolutionWidth = 1920;
	const int resolutionHeight = 1080;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* cursorTexture = nullptr;
	Uint32 lastTick = 0;
	Uint32 fpsTracker = 0;
	bool fullscreen = false;
	Uint8 clearR = 0;
	Uint8 clearG = 0;
	Uint8 clearB = 0;
	int windowWidth = 0;
	int windowHeight = 0;
	unsigned int frameCount = 0;
};