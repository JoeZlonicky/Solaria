#include "Projectile.h"

Projectile::Projectile(std::string filePath, double rot, double x, double y) : Sprite(filePath, x, y){
	maxSpeed = 15.0;
	playerRotation = rot;
}

void Projectile::update(){
	double moveX, moveY;
	setVelocity(maxSpeed, maxSpeed);
	moveX = getXVelocity() * (cos((playerRotation - 90) * 0.0174532925));
	moveY = getYVelocity() * (sin((playerRotation - 90) * 0.0174532925));

	move(moveX, moveY);

}
