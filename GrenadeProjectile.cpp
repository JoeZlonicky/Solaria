#include "GrenadeProjectile.h"

GrenadeProjectile::GrenadeProjectile(std::string filePath, double rot) : Projectile(filePath, rot) {
	playerRotation = rot;
	setVelocity(maxSpeed, maxSpeed);
}

void GrenadeProjectile::update(){
	double moveX, moveY;
	if (getXVelocity() >= 0 && getYVelocity() >= 0.01) {
		reduceVelocity(0.075, 0.075);
		moveX = getXVelocity() * (cos((playerRotation - 90) * 0.0174532925));
		moveY = getYVelocity() * (sin((playerRotation - 90) * 0.0174532925));

		move(moveX, moveY);
		
	}
	else {
		printf("Explode!");
	}
}
