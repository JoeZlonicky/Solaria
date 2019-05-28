#include "Asteroid.h"
#include "RandomGenerator.h"
#include <math.h>
#include <algorithm>

Asteroid::Asteroid(double x, double y) : Asteroid(randomSize(), x ,y) {
}

Asteroid::Asteroid(AsteroidSize size, double x, double y) : size(size), Sprite(getFilePath(size), x, y) {
	rotation = RandomGenerator::randint(0, 359);
	double speed = RandomGenerator::randint(MIN_SPEED, MAX_SPEED);
	xVelocity = sin(rotation) * speed;
	yVelocity = cos(rotation) * speed;
}

void Asteroid::hit() {
	destory = true;
}

void Asteroid::update() {
	x += xVelocity;
	y += yVelocity;
}

void Asteroid::destroy(std::vector<Asteroid>* asteroids) {
	if (size > SMALL) {
		AsteroidSize smallerSize = AsteroidSize(size - 1);
		asteroids->push_back(Asteroid(smallerSize, x, y));
		asteroids->push_back(Asteroid(smallerSize, x, y));
	}
}

bool Asteroid::shouldDestroy() {
	return destory;
}

const AsteroidSize Asteroid::randomSize() {
	return AsteroidSize(RandomGenerator::randint(SMALL, LARGE));
}

const std::string Asteroid::getFilePath(int size) {
	int type = RandomGenerator::randint(1, 3);
	switch (size) {
		case SMALL:
			return "assets/asteroidSmall" + std::to_string(type) + ".png";
			break;
		case MEDIUM:
			return "assets/asteroidMedium" + std::to_string(type) + ".png";
			break;
		case LARGE:
			return "assets/asteroidLarge" + std::to_string(type) + ".png";
			break;
		default:
			return "assets/asteroidSmall" + std::to_string(type) + ".png";
			break;
	}
}