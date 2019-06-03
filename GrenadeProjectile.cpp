#include "GrenadeProjectile.h"

GrenadeProjectile::GrenadeProjectile(std::string filePath, double rot, std::vector<Projectile*>* projectiles) : Projectile(filePath, rot) {
	playerRotation = rot;
	velocity = Vector(maxSpeed, maxSpeed);
	proj = projectiles;
}

void GrenadeProjectile::update(){
	if (velocity.x >= 0 && velocity.y >= 0.01) {
		reduceVelocity(0.075, 0.075);
		position.x += velocity.x * (cos((playerRotation - 90) * 0.0174532925));
		position.y += velocity.y * (sin((playerRotation - 90) * 0.0174532925));
	}
	else {
		if (!isExploded) {
			spawnShrapnel(getCenter().x, getCenter().y);
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
	}
}