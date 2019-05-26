#include "Asteroid.h"
#include "RandomGenerator.h"
#include <math.h>

Asteroid::Asteroid(int x, int y) : Asteroid(randomSize(), x ,y) {
	rotation = RandomGenerator::randint(0, 359);
	int speed = RandomGenerator::randint(MIN_SPEED, MAX_SPEED);
	xVelocity = sin(rotation) * speed;
	yVelocity = cos(rotation) * speed;
}

void Asteroid::update() {
	x += xVelocity;
	y += yVelocity;
}

Asteroid::Asteroid(AsteroidSize size, int x, int y) : Sprite(getFilePath(size), x, y) {
}

const AsteroidSize Asteroid::randomSize() {
	return AsteroidSize(RandomGenerator::randint(0, AsteroidSize::NUMBER_OF_SIZES));
}

const std::string Asteroid::getFilePath(int size) {
	switch (size) {
		case SMALL:
			return "assets/asteroidSmall1.png";
			break;
		case MEDIUM:
			return "assets/asteroidMedium1.png";
			break;
		case LARGE:
			return "assets/asteroidLarge1.png";
			break;
		default:
			return "assets/asteroidSmall1.png";
			break;
	}
}