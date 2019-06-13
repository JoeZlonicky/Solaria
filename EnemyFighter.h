#pragma once
#include "Player.h"
#include "Sprite.h"
#include "RandomGenerator.h"

class Player;

class EnemyFighter : public Sprite{
public:
	EnemyFighter(std::string filePath, double x, double y,
		double _health, double _movementSpeed, Player* player);

	void update();
	void track();

private:
	double health;
	double movementSpeed;
	Player* player;
	bool playerInRange = false;
	double movementTimer = 0;

};

