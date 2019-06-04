#pragma once
#include <string>
#include "Sprite.h"

class Planet : public Sprite {
public:
	Planet(std::string name, std::string imagePath, double orbitRate, double distanceFromSun);
	void update();
	std::string getName();

private:
	std::string name;
	double orbitRotation = 0.0;
	double orbitRate;
	double distanceFromSun;
};

