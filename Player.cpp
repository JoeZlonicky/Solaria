#include "Player.h"

#include "GrenadeProjectile.h"

Player::Player() : Ship("assets/player.png", 250, 100) {
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if(currentAmmo <= 0) {
		if (reloadTimer < 1000) {
			reloadTimer += 1;
		}
		else {
			reload();
			reloadTimer = 0;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_W]) {
		velocity = Vector(speed, speed);
		playerMove();
	}
	else if (currentKeyStates[SDL_SCANCODE_S]) {
		if (velocity.x >= 0 && velocity.y >= 0.01) {
			reduceVelocity(0.075, 0.075);
			playerMove();
		}
	}
	else if(velocity.x >= 0 && velocity.y >= 0.01){
		reduceVelocity(0.05, 0.05);
		playerMove();
	}
	else{
		velocity = Vector(0.0, 0.0);
	}

}

void Player::fireProjectile(std::vector<Projectile*>* projectiles, int mouseID){
	if(currentAmmo > 0){
		if (mouseID == 1) {
		leftMouseProjectile = new GrenadeProjectile("assets/bomb.png", rotation, projectiles);
		leftMouseProjectile->setCenter(getCenter().x, getCenter().y);
		leftMouseProjectile->setRotation(rotation);
		projectiles->push_back(leftMouseProjectile);
		}
		else if (mouseID == 3) {
			rightMouseProjectile = new Projectile("assets/projectile.png", rotation);
			rightMouseProjectile->setCenter(getCenter().x, getCenter().y);
			rightMouseProjectile->setRotation(rotation);
			projectiles->push_back(rightMouseProjectile);
		}
		currentAmmo -= 1;
	}
}

void Player::reload(){
	currentAmmo = max_ammo;
}

void Player::playerMove(){
	position.x += velocity.x * (cos((rotation - 90) * 0.0174532925));
	position.y += velocity.y * (sin((rotation - 90) * 0.0174532925));
}

void Player::calculateRotation(Display* display){
	double delta_x = ((double)display->getWindowWidth() / 2) - mousePosition.x;
	double delta_y = ((double)display->getWindowHeight() / 2) - mousePosition.y;
	rotation = (atan2(delta_y, delta_x) * 180.0000) / 3.1416 - 90;
}

void Player::updateMousePosition(int x, int y){
	mousePosition.x = x;
	mousePosition.y = y;
}

double Player::getAngle()
{
	return angle_deg;
}

int Player::getMaxAmmo() {
	return max_ammo;
}

int Player::getCurrentAmmo() {
	return currentAmmo;
}
