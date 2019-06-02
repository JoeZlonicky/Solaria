#pragma once
#include "Projectile.h"

class GrenadeProjectile : public Projectile{
public:
	GrenadeProjectile(std::string filePath, double rot);
	void update();

private:
	double maxSpeed = 5.0;
	double playerRotation;
};

