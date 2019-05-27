#pragma once
#include "Sprite.h"
#include "Player.h"

class Projectile : public Sprite
{
public:
	Projectile(std::string filePath, double rot, double x = 0, double y = 0);

	void update();

private:
	double maxSpeed = 0.0;
	Player* player = nullptr;
	double playerRotation;
};

