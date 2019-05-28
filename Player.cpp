#include "Player.h"
#include "Game.h"

Player::Player() : Sprite("assets/player.png", x, y) {
	maxSpeed = 5;
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

;	if (currentKeyStates[SDL_SCANCODE_W]) {
		setVelocity(maxSpeed, maxSpeed);
		playerMove();
	}
	else if (currentKeyStates[SDL_SCANCODE_S]) {
		if (getXVelocity() >= 0 && getYVelocity() >= 0.01) {
			reduceVelocity(0.075, 0.075);
			playerMove();
		}
	}
	else if(getXVelocity() >= 0 && getYVelocity() >= 0.01){
		reduceVelocity(0.05, 0.05);
		playerMove();
	}
	else{
		setVelocity(0.0, 0.0);
	}
}

void Player::fireProjectile(std::vector<Projectile>* projectiles){
	Projectile projectile = Projectile("assets/projectile.png", rotation);
	projectile.setCenter(getCenterX(), getCenterY());
	projectile.setRotation(rotation);
	projectiles->push_back(projectile);
}

void Player::playerMove(){
	double x, y;
	x = getXVelocity() * (cos((rotation - 90) * 0.0174532925));
	y = getYVelocity() * (sin((rotation - 90) * 0.0174532925));

	move(x, y);
}

void Player::calculateRotation(Display* display){
	double delta_y = ((double)display->getHeight() / 2) - yMouse;
	double delta_x = ((double)display->getWidth() / 2) - xMouse;
	rotation = (atan2(delta_y, delta_x) * 180.0000) / 3.1416 - 90;
}

void Player::setMouseCoords(int _xMouse, int _yMouse){
	yMouse = _yMouse;
	xMouse = _xMouse;
}

double Player::getAngle()
{
	return angle_deg;
}
