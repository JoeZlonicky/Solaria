#pragma once
#include "Projectile.h"
#include <vector>


class GrenadeProjectile : public Projectile{
public:
	GrenadeProjectile(std::string filePath, double rot, std::vector<Projectile*>* projectiles);
	void update();
	void spawnShrapnel(double x, double y);

	void move();

private:
	double maxSpeed = 10.0;
	double playerRotation;
	std::vector<Projectile*>* proj = nullptr;
	bool isExploded = false;
};

