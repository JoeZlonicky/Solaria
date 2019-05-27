#pragma once
#include <vector>
#include "Projectile.h"
#include "Sprite.h"
#include "Display.h"


class Player : public Sprite {

public:
	Player(std::string filePath, double x = 0, double y = 0);

	void update(std::vector<Projectile> &projectiles);

	void calculateRotation(Display* display);
	void setMouseCoords(int _xMouse, int _yMouse);
	double getAngle();

private:
	double maxSpeed;
	int xMouse = 0, yMouse = 0;
	double angle_deg = 0.0;

};

