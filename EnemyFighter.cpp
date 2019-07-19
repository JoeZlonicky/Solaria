#include "EnemyFighter.h"

EnemyFighter::EnemyFighter(std::string filePath, double x, double y, double _health, double _movementSpeed, 
	Player* _player): Sprite(filePath, x, y){
	health = _health;
	movementSpeed = _movementSpeed;
	player = _player;
}

void EnemyFighter::update(){
	
	if (!playerInRange && movementTimer <= 0) {
		setRotation(RandomGenerator::randdouble(0, 360));
		movementTimer += 1;
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

void EnemyFighter::takeDamage(int damageAmount){
	health -= damageAmount;
}
