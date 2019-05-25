#pragma once
#include "Sprite.h"

class Player : public Sprite {

public:
	Player(std::string filePath, double x = 0, double y = 0);

	void move(double movementX, double movementY);
	void update();


private:
	double speed;

};

