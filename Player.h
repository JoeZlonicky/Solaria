#pragma once
#include <vector>

#include "Sprite.h"
#include "Projectile.h"
#include "Display.h"
#include "Ship.h"


class Display;

class Player : public Ship {

public:
	Player();

	void update();
	void fireProjectile(std::vector<Projectile*>* projectiles, int mouseID);
	void reload();
	void playerMove();
	void calculateRotation(Display* display);

	void updateMousePosition(int x, int y);
	double getAngle();
	int getMaxAmmo();
	int getCurrentAmmo();

private:
	const double speed = 2;
	const int max_ammo = 10;

	Vector mousePosition;
	double angle_deg = 0.0;
	Projectile* leftMouseProjectile = nullptr;
	Projectile* rightMouseProjectile = nullptr;
	int currentAmmo = 10;
	int reloadTimer = 0;
};