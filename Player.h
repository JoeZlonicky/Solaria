#pragma once
#include <vector>

#include "Sprite.h"
#include "Projectile.h"
#include "Display.h"
#include "GrenadeProjectile.h"


class Display;
class Projectile;

class Player : public Sprite {

public:
	Player();

	void update();

	void fireProjectile(std::vector<Projectile> projectiles, int mouseID);
	void reload();

	void playerMove();
	void calculateRotation(Display* display);
	void setMouseCoords(int _xMouse, int _yMouse);
	double getAngle();

private:
	const double speed = 2;
	int xMouse = 0, yMouse = 0;
	double angle_deg = 0.0;
	Projectile leftMouseProjectile;
	Projectile rightMouseProjectile;
	int currentAmmo = 10;
	int maxAmmo = 10;

	int reloadTimer = 0;

};

