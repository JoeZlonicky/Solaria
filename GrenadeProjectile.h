#pragma once
#include <vector>

#include "Projectile.h"

class GrenadeProjectile : public Projectile {
public:
	GrenadeProjectile(std::string filePath, double rot, std::vector<Projectile> projectiles);
	void update();
	void spawnShrapnel(double x, double y);

	void move();

private:
	double maxSpeed = 10.0;
	double playerRotation;
	std::vector<Projectile> proj;
	bool isExploded = false;
};

