#pragma once
#include <string>
#include "Sprite.h"

class Planet : public Sprite {
public:
	Planet(std::string imagePath, double orbitRate, double distanceFromSun);
	void update();

private:
	double orbitRotation = 0.0;
	double orbitRate;
	double distanceFromSun;
};

