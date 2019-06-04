#include "Planet.h"
#include <math.h>
#include "RandomGenerator.h"

Planet::Planet(std::string name, std::string imagePath, double orbitRate, double distanceFromSun) : Sprite(imagePath), name(name), orbitRate(orbitRate), distanceFromSun(distanceFromSun) {
	orbitRotation = RandomGenerator::randint(0, 355) * 3.14159 / 180;
}

void Planet::update() {
	orbitRotation += orbitRate;
	double newX = cos(orbitRotation) * distanceFromSun;
	double newY = sin(orbitRotation) * distanceFromSun;
	setCenter(newX, newY);
}

std::string Planet::getName() {
	return name;
}
