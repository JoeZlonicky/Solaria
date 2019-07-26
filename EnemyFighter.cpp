#include "EnemyFighter.h"

EnemyFighter::EnemyFighter(std::string filePath, double x, double y, double _health, double _movementSpeed, 
	Player* _player): Sprite(filePath, x, y){
	health = _health;
	movementSpeed = _movementSpeed;
	player = _player;
}

void EnemyFighter::update(){
	
	determineIfPlayerInRange();

	if (!playerInRange && movementTimer <= 0) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer += 1;
	}
	else if (playerInRange) {
		track();
	}
	else if (movementTimer <= 500) {
		velocity = Vector(movementSpeed, movementSpeed);
		position.x += velocity.x * (cos((getRotation() - 90) * 0.0174532925));
		position.y += velocity.y * (sin((getRotation() - 90) * 0.0174532925));
		movementTimer += 1;
	}
	else {
		movementTimer = 0;
	}
	
}

void EnemyFighter::track(){
	rotation += 1;
	double newX = cos(rotation) * player->getPosition().x;
	double newY = sin(rotation) * player->getPosition().y;
	setCenter(newX, newY);
}

void EnemyFighter::takeDamage(double damage) {
	health -= damage;
	if (health <= 0) {
		printf("Fighter Dead!");
	}
}

void EnemyFighter::determineIfPlayerInRange(){
	double newX = pow((player->getPosition().x - position.x), 2);
	double newY = pow((player->getPosition().y - position.y), 2);

	double distance = sqrt(newX + newY);
	if (distance <= 550.0) {
		playerInRange = true;
	}
}
