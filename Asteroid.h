#pragma once
#include <string>
#include <vector>

#include "Sprite.h"

enum AsteroidType {
	SMALL,
	MEDIUM,
	LARGE
};

class Asteroid : public Sprite {
public:
	Asteroid(double x = 0, double y = 0);
	Asteroid(AsteroidType type, double x = 0, double y = 0);

	Asteroid(const Asteroid& ast);
	Asteroid& operator=(const Asteroid& ast);

	void hit();
	void update();
	void destroy(std::vector<Asteroid>* asteroids);
	bool breaksSmaller();

	AsteroidType getType();
	bool shouldDestroy();

private:
	AsteroidType randomSize();
	std::string getFilePath(int size);
	
	const int MIN_SPEED = 1;
	const int MAX_SPEED = 3;

	AsteroidType type;
	bool destory = false;
};

