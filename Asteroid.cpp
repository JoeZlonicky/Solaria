#include "Asteroid.h"
#include "RandomGenerator.h"
#include <math.h>
#include <algorithm>

Asteroid::Asteroid(double x, double y) : Asteroid(randomSize(), x ,y) {
}

Asteroid::Asteroid(AsteroidType type, double x, double y) : type(type), Sprite(getFilePath(type), x, y) {
	rotation = RandomGenerator::randint(0, 355);
	double speed = RandomGenerator::randint(MIN_SPEED, MAX_SPEED);
	velocity.x = sin(rotation) * speed;
	velocity.y = cos(rotation) * speed;
}

Asteroid::Asteroid(const Asteroid& ast) : Asteroid(ast.type, ast.position.x, ast.position.y) {
	rotation = ast.rotation;
	texture = ast.texture;
	velocity = ast.velocity;
	size = ast.size;
	destory = ast.destory;
}

Asteroid& Asteroid::operator=(const Asteroid& ast) {
	position = ast.position;
	rotation = ast.rotation;
	size = ast.size;
	texture = ast.texture;
	velocity = ast.velocity;
	size = ast.size;
	destory = ast.destory;
	return *this;
}

AsteroidType Asteroid::getType() {
	return type;
}

void Asteroid::hit() {
	printf("Object hit\n");
	destory = true;
}

void Asteroid::update() {
	position.x += velocity.x;
	position.y += velocity.y;
}

void Asteroid::destroy(std::vector<Asteroid>* asteroids) {
	if (type > SMALL) {
		AsteroidType smallerSize = AsteroidType(type - 1);
	}
}

bool Asteroid::shouldDestroy() {
	return destory;
}

bool Asteroid::breaksSmaller() {
	return type > SMALL;
}

AsteroidType Asteroid::randomSize() {
	return AsteroidType(RandomGenerator::randint(SMALL, LARGE));
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