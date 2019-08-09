#include "Ship.h"

Ship::Ship(std::string filePath, double max_health, double max_armor) : Sprite(filePath){
	maxHealth = max_health;
	maxArmor = max_armor;
	currentArmor = maxArmor;
	currentHealth = maxHealth;
}

void Ship::takeDamage(double amount){
	//if the ship has armor then damage it
	//if the armor breaks, carry over damage to health
	if (currentArmor > 0) {
		currentArmor -= amount;
		if (currentArmor < 0) {
			currentHealth -= -currentArmor;
			currentArmor = 0;
		}
	}
	//if no armor the damage health instead
	else {
		currentHealth -= amount;
	}
	//if health falls below 0 then destroy the ship
	if (currentHealth <= 0) {
		currentHealth = 0;
		IsDestroyed = true;
		printf("Fighter Destroyed.");
	}
}

bool Ship::isDestroyed() {
	return IsDestroyed;
}
