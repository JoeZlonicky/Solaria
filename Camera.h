#pragma once
#include "Sprite.h"
#include "Map.h"

class Camera {
public:
	Camera(int displayWidth, int displayHeight);
	void update(Sprite* target);
	SDL_Rect apply(SDL_Rect rect);
	void updateMap(Map* newMap);
	double getX();
	double getY();

private:
	Map* map = nullptr;
	double x = 0;
	double y = 0;
	int displayWidth;
	int displayHeight;

};

