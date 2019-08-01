#pragma once
#include "Player.h"
#include "Sprite.h"
#include "RandomGenerator.h"
#include "Vector.h"
#include "Timer.h"
#include <math.h> 

#define PI 3.14159265

class Player;

class EnemyFighter : public Sprite{
public:
	EnemyFighter(std::string filePath, double x, double y,
		double _health, double _movementSpeed, Player* player);

	void update();
	void track();
	void takeDamage(double damage);
	double determinePlayerDistance();

private:
	double health;
	double movementSpeed;
	Player* player;
	bool playerInRange = false;
	double movementTimer = 0;
	Timer* timer = new Timer();

};

