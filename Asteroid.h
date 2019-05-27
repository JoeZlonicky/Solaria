#pragma once
#include <string>
#include <vector>
#include "Sprite.h"

enum AsteroidSize {
	SMALL,
	MEDIUM,
	LARGE
};

class Asteroid : public Sprite {
public:
	Asteroid(int x = 0, int y = 0);
	Asteroid(AsteroidSize size, int x = 0, int y = 0);
	void hit();
	void update();
	AsteroidSize getSize();
	bool shouldDestroy();
	bool breaksSmaller();
private:
	static const AsteroidSize randomSize();
	static const std::string getFilePath(int size);
	AsteroidSize size;
	bool destory = false;
	const int MIN_SPEED = 1;
	const int MAX_SPEED = 3;
};

