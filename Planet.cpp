#include "Planet.h"
#include <math.h>

Planet::Planet(std::string imagePath, double orbitRate, double distanceFromSun) : Sprite(imagePath), orbitRate(orbitRate), distanceFromSun(distanceFromSun) {
}

void Planet::update() {
	orbitRotation += orbitRate;
	double newX = cos(orbitRotation) * distanceFromSun;
	double newY = sin(orbitRotation) * distanceFromSun;
	setCenter(newX, newY);
}
