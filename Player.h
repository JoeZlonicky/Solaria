#pragma once
#include "Sprite.h"

class Player : public Sprite {

public:
	Player(std::string filePath, int x, int y);

	void move(double movementX, double movementY);
	void update();


private:
	double speed;

};

