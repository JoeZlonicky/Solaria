#pragma once
#include "Sprite.h"

enum AsteroidSize {
	SMALL,
	MEDIUM,
	LARGE
};

class Asteroid : public Sprite {
public:
	Asteroid(int x, int y);
	void hit();
private:
	AsteroidSize size;

};

