#pragma once
#include <vector>
#include "Projectile.h"
#include "GrenadeProjectile.h"
#include "Sprite.h"
#include "Display.h"

class Display;

class Player : public Sprite {

public:
	Player();

	void update();

	void fireProjectile(std::vector<Projectile>* projectiles);

	void playerMove();
	void calculateRotation(Display* display);
	void setMouseCoords(int _xMouse, int _yMouse);
	double getAngle();

private:
	const double speed = 2;
	int xMouse = 0, yMouse = 0;
	double angle_deg = 0.0;

};

