#include "Player.h"
#include "Game.h"

Player::Player(std::string filePath, 
	double x, double y) : Sprite(filePath, x, y) {
	maxSpeed = 5;
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
;	if (currentKeyStates[SDL_SCANCODE_W]) {
		double x, y;
		setVelocity(maxSpeed, maxSpeed);
		x = getXVelocity() * (cos((rotation - 90) * 0.0174532925));
		y = getYVelocity() * (sin((rotation - 90) * 0.0174532925));

		move(x, y);
	}
	else if(getXVelocity() >= 0 && getYVelocity() >= 0.01){
		reduceVelocity(0.05, 0.05);
		double x, y;
		x = getXVelocity() * (cos((rotation - 90) * 0.0174532925));
		y = getYVelocity() * (sin((rotation - 90) * 0.0174532925));

		move(x, y);
	}
	else{
		setVelocity(0.0, 0.0);
	}

	if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT)) {
		Projectile* projectile = new Projectile("assets/enemy.png", rotation, x, y);
		//Call addProjectile

	}
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
