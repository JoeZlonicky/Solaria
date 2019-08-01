#include "EnemyMotherShip.h"

#include "RandomGenerator.h"

EnemyMotherShip::EnemyMotherShip(std::string filePath, double x, double y, double _health, double _movementSpeed, double _enemySpawnTime, Player* _player) : Sprite(filePath, x, y){
	health = _health;
	movementSpeed = _movementSpeed;
	enemySpawnTime = _enemySpawnTime;
	player = _player;
}

void EnemyMotherShip::update(std::vector<EnemyFighter*>* enemyFighters){
	
	enemySpawnTime += 1;

	if (!playerInRange && movementTimer <= 0) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer += 1;
	} else if (movementTimer <= 500){
		velocity = Vector(movementSpeed, movementSpeed);
		position.x += velocity.x * (cos((getRotation() - 90) * 0.0174532925));
		position.y += velocity.y * (sin((getRotation() - 90) * 0.0174532925));
		movementTimer += 1;
	}
	else {
		movementTimer = 0;
	}

	if (enemySpawnTime >= 250 && enemyFighters->size() <= 0) {
		spawnEnemy(enemyFighters);
		enemySpawnTime = 0;
	}

}

void EnemyMotherShip::track(){

}

void EnemyMotherShip::spawnEnemy(std::vector<EnemyFighter*>* enemyFighters){
	EnemyFighter* enemy = new EnemyFighter("assets/enemy.png", getPosition().x, getPosition().y, 10, 2, player);
	enemy->setCenter(getCenter().x, getCenter().y);
	enemy->setRotation(rotation);
	enemyFighters->push_back(enemy);
}
