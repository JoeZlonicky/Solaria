#pragma once
#include "Sprite.h"
#include "Map.h"

class Camera {
public:
	Camera(int displayWidth, int displayHeight);
	void update(Sprite* target);
	SDL_Rect apply(SDL_Rect rect);
	void updateMap(Map* newMap);
	int getX();
	int getY();

private:
	Map* map = nullptr;
	int x = 0;
	int y = 0;
	int displayWidth;
	int displayHeight;

};

