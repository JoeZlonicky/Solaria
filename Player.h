#pragma once
#include <vector>

#include "Sprite.h"
#include "Projectile.h"
#include "Display.h"


class Display;

class Player : public Sprite {

public:
	Player();

	void update();
	void fireProjectile(std::vector<Projectile*>* projectiles, int mouseID);
	void reload();
	void playerMove();
	void calculateRotation(Display* display);

	void updateMousePosition(int x, int y);
	double getAngle();

private:
	const double SPEED = 2;
	const int MAX_AMMO = 10;

	Vector mousePosition;
	double angle_deg = 0.0;
	Projectile* leftMouseProjectile = nullptr;
	Projectile* rightMouseProjectile = nullptr;
	int currentAmmo = 10;
	int reloadTimer = 0;
};