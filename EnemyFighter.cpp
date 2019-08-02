#include "EnemyFighter.h"

EnemyFighter::EnemyFighter(std::string filePath, double x, double y, double _health, double _movementSpeed, 
	Player* _player): Ship(filePath, _health, 100.0){
	health = _health;
	movementSpeed = _movementSpeed;
	player = _player;
	movementTimer.startTimer();
}

void EnemyFighter::update(std::vector<Projectile*>* projectiles){

	if (determinePlayerDistance() <= 550) { 
		playerInRange = true; 
		fireTimer.startTimer();
	
	}

	if (!playerInRange && movementTimer.currentTime() >= 5000) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer.endTimer();
		movementTimer.startTimer();
	}
	else if (playerInRange) {
		track();
		fire(projectiles);
	}
	else if (movementTimer.currentTime() <= 5000) {
		velocity = Vector(movementSpeed, movementSpeed);
		position.x += velocity.x * (cos((getRotation() - 90) * 0.0174532925));
		position.y += velocity.y * (sin((getRotation() - 90) * 0.0174532925));
	}
	
}

void EnemyFighter::track(){
	Vector facingVec = player->getPosition() - getPosition();
	rotation = (atan2(facingVec.y, facingVec.x) * 180.0000) / PI + 90;	
}

void EnemyFighter::fire(std::vector<Projectile*>* projectiles) {
	if (fireTimer.currentTime() >= 1000) {
		projectile = new Projectile("assets/projectile.png", rotation);
		projectile->setCenter(getCenter().x, getCenter().y);
		projectile->setRotation(rotation);
		projectiles->push_back(projectile);
		fireTimer.endTimer();
		fireTimer.startTimer();
	}
}

double EnemyFighter::determinePlayerDistance() {
	double newX = pow((player->getPosition().x - position.x), 2);
	double newY = pow((player->getPosition().y - position.y), 2);

	double distance = sqrt(newX + newY);
	return distance;
}

