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
	Asteroid(const Asteroid& ast);
	Asteroid& operator=(const Asteroid& ast);
	AsteroidSize getSize();
	void hit();
	void update();
	void destroy(std::vector<Asteroid>* asteroids);
	bool shouldDestroy();
	bool breaksSmaller();

private:
	AsteroidSize randomSize();
	std::string getFilePath(int size);
	
	AsteroidSize size;
	bool destory = false;
	
	const int MIN_SPEED = 1;
	const int MAX_SPEED = 3;
};

