#include "GrenadeProjectile.h"

GrenadeProjectile::GrenadeProjectile(std::string filePath, double rot, std::vector<Projectile*>* projectiles) : Projectile(filePath, rot) {
	playerRotation = rot;
	setVelocity(maxSpeed, maxSpeed);
	proj = projectiles;
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
		if (!isExploded) {
			spawnShrapnel(getCenterX(), getCenterY());
			isExploded = true;
		}
	}
}

void GrenadeProjectile::spawnShrapnel(double x, double y) {
	double rotation = 0.0;
	for (int i = 0; i < 8; i++)
	{
		Projectile* projectile = new Projectile("assets/projectile.png", rotation);
		projectile->setCenter(x, y);
		projectile->setRotation(rotation);
		rotation += 45.0;
		proj->push_back(projectile);
		printf("Rotation: %f Projectile Rotation: %f\n", rotation, projectile->getRotation());
	}
}