#include "Asteroid.h"
#include "RandomGenerator.h"
#include <math.h>
#include <algorithm>

Asteroid::Asteroid(int x, int y) : Asteroid(randomSize(), x ,y) {
}

void Asteroid::hit() {
	destory = true;
}

void Asteroid::update() {
	x += xVelocity;
	y += yVelocity;
}

AsteroidSize Asteroid::getSize() {
	return size;
}

bool Asteroid::shouldDestroy() {
	return destory;
}

bool Asteroid::breaksSmaller() {
	return size > SMALL;
}

Asteroid::Asteroid(AsteroidSize size, int x, int y) : size(size), Sprite(getFilePath(size), (double)x, (double)y) {
	rotation = RandomGenerator::randint(0, 359);
	double speed = RandomGenerator::randint(MIN_SPEED, MAX_SPEED);
	xVelocity = sin(rotation) * speed;
	yVelocity = cos(rotation) * speed;
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
