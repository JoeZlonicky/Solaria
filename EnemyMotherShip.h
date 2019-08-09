#pragma once
#include "Player.h"
#include "Sprite.h"
#include "RandomGenerator.h"
#include "EnemyFighter.h"
#include "Timer.h"

class EnemyMotherShip : public Sprite{
public:
	EnemyMotherShip(std::string filePath, double x, double y, double _health, double _movementSpeed,
		double _enemySpawnTime, Player* _player);

	void update(std::vector<EnemyFighter*>* enemyFighters);
	void track();
	void spawnEnemy(std::vector<EnemyFighter*>* enemyFighters);

private:
	double health;
	double movementSpeed;
	Timer enemySpawnTimer;
	Player* player;
	bool playerInRange = false;
	Timer movementTimer;
};

