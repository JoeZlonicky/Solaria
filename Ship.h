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
	double maxHealth;
	double currentHealth;
	
	double maxArmor;
	double currentArmor;

	bool IsDestroyed = false;

};

