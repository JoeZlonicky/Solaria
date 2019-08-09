#include "Player.h"

#include "GrenadeProjectile.h"

Player::Player() : Ship("assets/player.png", 250, 100) {
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if(currentAmmo <= 0) {
		//If out of ammo. after 5 seconds reload
		reloadTimer.startTimer();
		if (reloadTimer.currentTime >= 5000) {
			reload();
			reloadTimer.endTimer();
		}
	}
	if (currentKeyStates[SDL_SCANCODE_W]) {
		//Set player velocity to max speed and move
		velocity = Vector(maxSpeed, maxSpeed);
		playerMove();
	}
	else if (currentKeyStates[SDL_SCANCODE_S]) {
		//If not stopped. Slowdown and move
		if (velocity.x >= 0 && velocity.y >= 0.01) {
			reduceVelocity(0.075, 0.075);
			playerMove();
		}
	}
	else if(velocity.x >= 0 && velocity.y >= 0.01){
		//If not stopped. Slowdown and move
		reduceVelocity(0.05, 0.05);
		playerMove();
	}
	else{
		//Else make sure the player has stopped moving
		velocity = Vector(0.0, 0.0);
	}

}

void Player::fireProjectile(std::vector<Projectile*>* projectiles, int mouseID){
	if(currentAmmo > 0){
		if (mouseID == 1) {
			//Create projectile and assign it to left mouse button
			//Set the center of the projectile to the players center
			//Set the rotation of the projectile to the players
			//Add the projectile to the vector to be rendered
			leftMouseProjectile = new GrenadeProjectile("assets/bomb.png", rotation, projectiles, false);
			leftMouseProjectile->setCenter(getCenter().x, getCenter().y);
			leftMouseProjectile->setRotation(rotation);
			projectiles->push_back(leftMouseProjectile);
		}
		else if (mouseID == 3) {
			//Create projectile and assign it to left mouse button
			//Set the center of the projectile to the players center
			//Set the rotation of the projectile to the players
			//Add the projectile to the vector to be rendered
			rightMouseProjectile = new Projectile("assets/projectile.png", rotation, false);
			rightMouseProjectile->setCenter(getCenter().x, getCenter().y);
			rightMouseProjectile->setRotation(rotation);
			projectiles->push_back(rightMouseProjectile);
		}
		currentAmmo -= 1;
	}
}

void Player::reload(){
	currentAmmo = maxAmmo;
}

void Player::playerMove(){
	//Move player based on rotation
	position.x += velocity.x * (cos((rotation - 90) * 0.0174532925));
	position.y += velocity.y * (sin((rotation - 90) * 0.0174532925));
}

void Player::calculateRotation(Display* display){
	//Calculate rotation based on where the mouse is
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
	return maxAmmo;
}

int Player::getCurrentAmmo() {
	return currentAmmo;
}
