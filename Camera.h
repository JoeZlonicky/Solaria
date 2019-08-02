#pragma once
#include "Display.h"
#include "SDL.h"
#include "Sprite.h"
#include "Vector.h"
#include "Map.h"

class Display;

class Camera {
public:
	Camera(Display* display);

	void update(Sprite* target);
	SDL_Rect apply(SDL_Rect rect);
	Vector apply(Vector vec);

	Vector getPosition();

private:
	Display* display = nullptr;
	Vector position;
};

