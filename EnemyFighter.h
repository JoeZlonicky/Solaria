#pragma once
#include "Player.h"
#include "Sprite.h"
#include "RandomGenerator.h"
#include "Vector.h"
#include "Timer.h"
#include "Projectile.h"
#include "Ship.h"
#include <math.h> 

#define PI 3.14159265

class Player;

class EnemyFighter : public Ship{
public:
	EnemyFighter(std::string filePath, double x, double y,
		double _health, double _movementSpeed, Player* player);

	void update(std::vector<Projectile*>* projectiles);
	void track();
	void fire(std::vector<Projectile*>* projectiles);
	double determinePlayerDistance();

private:
	double health;
	double movementSpeed;
	Player* player;
	bool playerInRange = false;
	Timer movementTimer = Timer();
	Timer fireTimer = Timer();
	Projectile* projectile = nullptr;

};

