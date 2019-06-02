#pragma once
#include "Projectile.h"

class GrenadeProjectile : public Projectile{
public:
	GrenadeProjectile(std::string filePath, double rot);

private:
	void update();
	double maxSpeed = 2.0;
	double playerRotation;
};

