#pragma once
#include "Display.h"
#include "SDL.h"
#include "Sprite.h"
#include "Vector.h"
#include "Map.h"

class Display;
class Map;

class Camera {
public:
	Camera(Display* display);

	void update(Sprite* target);
	SDL_Rect apply(SDL_Rect rect);
	Vector apply(Vector vec);
	void setMap(Map* map);
	double getX();
	double getY();

private:
	Map* map = nullptr;
	Display* display = nullptr;
	double x = 0;
	double y = 0;
};

