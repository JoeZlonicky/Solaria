#include "EnemyFighter.h"

EnemyFighter::EnemyFighter(std::string filePath, double x, double y, double _health, double _movementSpeed, 
	Player* _player): Ship(filePath, _health, 100.0){
	health = _health;
	movementSpeed = _movementSpeed;
	player = _player;
	movementTimer.startTimer();
}

void EnemyFighter::update(std::vector<Projectile*>* projectiles){

	//if the player is in range then start firing at him and track it
	if (determinePlayerDistance() <= 550) { 
		playerInRange = true; 
		fireTimer.startTimer();
	
	}

	//if the player is not in range and the ship has not changed directions in the past 5 seconds
	//then randomly change directions and restart the timer
	if (!playerInRange && movementTimer.currentTime() >= 5000) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer.restartTimer();
	}
	//if player is in range then track and fire at him
	else if (playerInRange) {
		track();
		fire(projectiles);
	}
	//if the ship has changed directions in the past 5 seconds then set velocity to max speed
	//and move based on ships rotation
	else if (movementTimer.currentTime() <= 5000) {
		velocity = Vector(movementSpeed, movementSpeed);
		position.x += velocity.x * (cos((getRotation() - 90) * 0.0174532925));
		position.y += velocity.y * (sin((getRotation() - 90) * 0.0174532925));
	}
	
}

void EnemyFighter::track(){
	//look at the player
	Vector facingVec = player->getPosition() - getPosition();
	rotation = (atan2(facingVec.y, facingVec.x) * 180.0000) / PI + 90;	
}

void EnemyFighter::fire(std::vector<Projectile*>* projectiles) {
	//every second the ship fires a projectile based on its rotation
	//then restarts the fire timer
	if (fireTimer.currentTime() >= 1000) {
		projectile = new Projectile("assets/projectile.png", rotation, false);
		projectile->setCenter(getCenter().x, getCenter().y);
		projectile->setRotation(rotation);
		projectiles->push_back(projectile);
		fireTimer.restartTimer();
	}
}

double EnemyFighter::determinePlayerDistance() {
	//determine players distance away from the current ships location
	double newX = pow((player->getPosition().x - position.x), 2);
	double newY = pow((player->getPosition().y - position.y), 2);

	double distance = sqrt(newX + newY);
	return distance;
}

