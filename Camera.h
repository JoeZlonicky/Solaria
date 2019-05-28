#pragma once
#include "Sprite.h"
#include "Display.h"
#include "Map.h"

class Display;
class Map;

class Camera {
public:
	Camera(Display* display);

	void update(Sprite* target);
	SDL_Rect apply(SDL_Rect rect);
	void setMap(Map* map);
	double getX();
	double getY();

private:
	Map* map = nullptr;
	Display* display = nullptr;
	double x = 0;
	double y = 0;
};

