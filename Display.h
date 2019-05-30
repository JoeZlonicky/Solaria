#pragma once
#include <SDL.h>
#include <string>
#include "Sprite.h"
#include "Label.h"
#include "Map.h"
#include "Camera.h"

class Camera;

class Display {
public:
	Display(std::string title, bool fullscreen);
	Display(std::string title, int width, int height);

	void clear();
	void update();
	void free();
	void setClearColor(Uint8 r, Uint8 g, Uint8 b);
	void draw(Sprite* sprite, Camera* camera = nullptr);
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
	Uint32 starting_tick;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* cursorTexture = nullptr;
	int cursorSize = 16;
	int fps = 60;
	bool fullscreen = false;
	Uint8 clearR = 0;
	Uint8 clearG = 0;
	Uint8 clearB = 0;
	int width = 0;
	int height = 0;
};