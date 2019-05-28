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
	Asteroid(double x = 0, double y = 0);
	Asteroid(AsteroidSize size, double x = 0, double y = 0);
	void hit();
	void update();
	void destroy(std::vector<Asteroid>* asteroids);
	bool shouldDestroy();

private:
	static const AsteroidSize randomSize();
	static const std::string getFilePath(int size);
	AsteroidSize size;
	bool destory = false;
	
	const int MIN_SPEED = 1;
	const int MAX_SPEED = 3;
};

