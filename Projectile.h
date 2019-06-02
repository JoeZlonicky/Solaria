#pragma once
#include "Sprite.h"

class Projectile : public Sprite {
public:
	Projectile(std::string filePath, double rot, double x = 0, double y = 0);

	virtual void update();

private:
	double maxSpeed = 0.0;
	double playerRotation;
};

