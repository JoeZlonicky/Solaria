#pragma once
#include <SDL.h>
#include "Display.h"
#include "Sprite.h"
#include "Vector.h"

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

