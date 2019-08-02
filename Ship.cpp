#include "Ship.h"

Ship::Ship(std::string filePath, double max_health, double max_armor) : Sprite(filePath){
	MAX_HEALTH = max_health;
	MAX_ARMOR = max_armor;
	CURRENT_ARMOR = MAX_ARMOR;
	CURRENT_HEALTH = MAX_HEALTH;
}

void Ship::takeDamage(double amount){
	if (CURRENT_ARMOR > 0) {
		CURRENT_ARMOR -= amount;
		if (CURRENT_ARMOR < 0) {
			CURRENT_HEALTH -= -CURRENT_ARMOR;
			CURRENT_ARMOR = 0;
		}
	}
	else {
		CURRENT_HEALTH -= amount;
	}

	if (CURRENT_HEALTH <= 0) {
		CURRENT_HEALTH = 0;
		IsDestroyed = true;
		printf("Fighter Destroyed.");
	}
}

bool Ship::isDestroyed() {
	return IsDestroyed;
}
