#include "Asteroid.h"
#include "RandomGenerator.h"
#include <math.h>
#include <algorithm>

Asteroid::Asteroid(double x, double y) : Asteroid(randomSize(), x ,y) {
}

Asteroid::Asteroid(AsteroidSize size, double x, double y) : size(size), Sprite(getFilePath(size), x, y) {
	rotation = RandomGenerator::randint(0, 355);
	double speed = RandomGenerator::randint(MIN_SPEED, MAX_SPEED);
	xVelocity = sin(rotation) * speed;
	yVelocity = cos(rotation) * speed;
}

Asteroid::Asteroid(const Asteroid& ast) : Asteroid(ast.size, ast.x, ast.y) {
	rotation = ast.rotation;
	texture = ast.texture;
	xVelocity = ast.xVelocity;
	yVelocity = ast.yVelocity;
	width = ast.width;
	height = ast.height;
	destory = ast.destory;
}

Asteroid& Asteroid::operator=(const Asteroid& ast) {
	x = ast.x;
	y = ast.y;
	rotation = ast.rotation;
	size = ast.size;
	texture = ast.texture;
	xVelocity = ast.xVelocity;
	yVelocity = ast.yVelocity;
	width = ast.width;
	height = ast.height;
	destory = ast.destory;
	return *this;
}

AsteroidSize Asteroid::getSize() {
	return size;
}

void Asteroid::hit() {
	printf("Object hit\n");
	destory = true;
}

void Asteroid::update() {
	x += xVelocity;
	y += yVelocity;
}

void Asteroid::destroy(std::vector<Asteroid>* asteroids) {
	if (size > SMALL) {
		AsteroidSize smallerSize = AsteroidSize(size - 1);
	}
}

bool Asteroid::shouldDestroy() {
	return destory;
}

bool Asteroid::breaksSmaller() {
	return size > SMALL;
}

AsteroidSize Asteroid::randomSize() {
	return AsteroidSize(RandomGenerator::randint(SMALL, LARGE));
}

std::string Asteroid::getFilePath(int size) {
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