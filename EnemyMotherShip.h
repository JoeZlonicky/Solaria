#pragma once
#include "Player.h"
#include "Sprite.h"
#include "RandomGenerator.h"

class EnemyMotherShip : public Sprite{
public:
	EnemyMotherShip(std::string filePath, double x, double y, double _health, double _movementSpeed,
		double _enemySpawnTime, Player* _player);

	void update();
	void track();
	void spawnEnemy();

private:
	double health;
	double movementSpeed;
	double enemySpawnTime;
	Player* player;
	bool playerInRange = false;
	double movementTimer = 0;

};

