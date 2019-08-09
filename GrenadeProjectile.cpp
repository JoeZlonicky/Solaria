#include "GrenadeProjectile.h"

GrenadeProjectile::GrenadeProjectile(std::string filePath, double rot, bool friendlyFire, std::vector<Projectile*>* projectiles) : Projectile(filePath, rot, friendlyFire) {
	playerRotation = rot;
	velocity = Vector(maxSpeed, maxSpeed);
	proj = projectiles;
}

void GrenadeProjectile::update(){
	move();
}

void GrenadeProjectile::move() {
	if (velocity.x >= 0 && velocity.y >= 0.01) {
		//if projectile has not stopped slow down and move based on players rotation
		reduceVelocity(0.075, 0.075);
		position.x += velocity.x * (cos((playerRotation - 90) * 0.0174532925));
		position.y += velocity.y * (sin((playerRotation - 90) * 0.0174532925));
	}
	else {
		if (!isExploded) {
			//if it has stopped moving then explode!
			spawnShrapnel(getCenter().x, getCenter().y);
			isExploded = true;
		}
	}
}

void GrenadeProjectile::spawnShrapnel(double x, double y) {
	double rotation = 0.0;
	for (int i = 0; i < 8; i++)
	{
		//Create projectile and assign it to left mouse button
		//Set the center of the projectile to the grenades center
		//Set the rotation of the projectile to the grenade
		//increase rotation for next piece of shrapnel
		//Add the projectile to the vector to be rendered
		Projectile* projectile = new Projectile("assets/projectile.png", rotation, true);
		projectile->setCenter(x, y);
		projectile->setRotation(rotation);
		rotation += 45.0;
		proj->push_back(projectile);
	}

}