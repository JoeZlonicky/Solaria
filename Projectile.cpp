#include "Projectile.h"

Projectile::Projectile(std::string filePath, double rot, double x, double y) : Sprite(filePath, x, y){
	maxSpeed = 15.0;
	this->player = player;
	playerRotation = rot;
}

void Projectile::update()
{
	double x, y;
	setVelocity(maxSpeed, maxSpeed);
	x = getXVelocity() * (cos((playerRotation - 90) * 0.0174532925));
	y = getYVelocity() * (sin((playerRotation - 90) * 0.0174532925));

	move(x, y);
}
