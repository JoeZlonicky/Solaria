#include "Projectile.h"

Projectile::Projectile(std::string filePath, double rot, bool friendlyFire, double x, double y) : Sprite(filePath, x, y){
	maxSpeed = 15.0;
	playerRotation = rot;
	canFriendlyFire = friendlyFire;
}

void Projectile::update(){
	move();
}

void Projectile::move(){
	//Set projectile to maxSpeed and move based on players rotation
	velocity = Vector(maxSpeed, maxSpeed);
	position.x += velocity.x * (cos((playerRotation - 90) * 0.0174532925));
	position.y += velocity.y * (sin((playerRotation - 90) * 0.0174532925));
}
