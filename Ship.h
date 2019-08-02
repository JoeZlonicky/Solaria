#pragma once
#include "Sprite.h"
#include <stdio.h>

class Ship : public Sprite
{
public:
	Ship(std::string filePath, double max_health, double max_armor);
	
	void takeDamage(double amount);

	bool isDestroyed();


private:
	double MAX_HEALTH;
	double CURRENT_HEALTH;
	
	double MAX_ARMOR;
	double CURRENT_ARMOR;

	bool IsDestroyed = false;

};

