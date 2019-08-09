#pragma once
#include "Sprite.h"

class Projectile : public Sprite {
public:
	Projectile(std::string filePath, double rot, bool friendlyFire, double x = 0, double y = 0);

	virtual void update();

	virtual void move();

private:
	double maxSpeed = 0.0;
	double playerRotation;
	bool canFriendlyFire = false;

};

