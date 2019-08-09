#include "EnemyMotherShip.h"

#include "RandomGenerator.h"

EnemyMotherShip::EnemyMotherShip(std::string filePath, double x, double y, double _health, double _movementSpeed, double _enemySpawnTime, Player* _player) : Sprite(filePath, x, y){
	health = _health;
	movementSpeed = _movementSpeed;
	player = _player;
	movementTimer.startTimer();
	enemySpawnTimer.startTimer();
}

void EnemyMotherShip::update(std::vector<EnemyFighter*>* enemyFighters){
	
	//if the player is not in range and the ship has not changed direction in the past 5 seconds
	//randomly change direction and restart timer
	if (!playerInRange && movementTimer.currentTime >= 5000) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer.restartTimer();

	//if the ship has changed direction in the past 5 seconds then move based on rotation
	} else if (movementTimer.currentTime() <= 4999){
		velocity = Vector(movementSpeed, movementSpeed);
		position.x += velocity.x * (cos((getRotation() - 90) * 0.0174532925));
		position.y += velocity.y * (sin((getRotation() - 90) * 0.0174532925));
	}
	//if the ship has not spawned an enemy in the past 4.5 seconds then spawn one and restart timer
	if (enemySpawnTimer.currentTime >= 4500) {
		spawnEnemy(enemyFighters);
		enemySpawnTimer.restartTimer();
	}

}

void EnemyMotherShip::track(){

}

void EnemyMotherShip::spawnEnemy(std::vector<EnemyFighter*>* enemyFighters){
	//spawn enemy based on ships rotation and add it to the vector to be rendered
	EnemyFighter* enemy = new EnemyFighter("assets/enemy.png", getPosition().x, getPosition().y, 75, 2, player);
	enemy->setCenter(getCenter().x, getCenter().y);
	enemy->setRotation(rotation);
	enemyFighters->push_back(enemy);
}
