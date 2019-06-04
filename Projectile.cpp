#include "Projectile.h"

Projectile::Projectile(std::string filePath, double rot, double x, double y) : Sprite(filePath, x, y){
	maxSpeed = 15.0;
	playerRotation = rot;
}

void Projectile::update(){
	move();
}

void Projectile::move(){
	velocity = Vector(maxSpeed, maxSpeed);
	position.x += velocity.x * (cos((playerRotation - 90) * 0.0174532925));
	position.y += velocity.y * (sin((playerRotation - 90) * 0.0174532925));
}
