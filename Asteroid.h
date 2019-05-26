#pragma once
#include <string>
#include "Sprite.h"

enum AsteroidSize {
	SMALL,
	MEDIUM,
	LARGE,
	NUMBER_OF_SIZES
};

class Asteroid : public Sprite {
public:
	Asteroid(int x = 0, int y = 0);
	void hit();
	void update();
private:
	Asteroid(AsteroidSize size, int x, int y);
	static const AsteroidSize randomSize();
	static const std::string getFilePath(int size);
	AsteroidSize size;
	const double MIN_SPEED = 1;
	const double MAX_SPEED = 3;
};

