#include "Player.h"
#include "Game.h"

Player::Player(std::string filePath, double x, double y) : Sprite(filePath, x, y) {
	maxSpeed = 5;

}

void Player::move(double movementX, double movementY){
	Sprite::moveX(movementX);
	Sprite::moveY(movementY);
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_W]) {
		double x, y;
		setVelocity(maxSpeed, maxSpeed);
		x = getXVelocity() * (cos((angle_deg - 90) * 0.0174532925));
		y = getYVelocity() * (sin((angle_deg - 90) * 0.0174532925));

		move(x, y);
	}
	else if(getXVelocity() >= 0 && getYVelocity() >= 0.01){
		reduceVelocity(0.05, 0.05);
		double x, y;
		x = getXVelocity() * (cos((angle_deg - 90) * 0.0174532925));
		y = getYVelocity() * (sin((angle_deg - 90) * 0.0174532925));

		move(x, y);
	}
	else{
		setVelocity(0.0, 0.0);
	}

	printf("X Velocity: %f Y Velocity: %f \n", getXVelocity(), getYVelocity());
	
}

void Player::calculateRotation(Display* display){
	double delta_y = (display->getHeight() / 2) - Player::yMouse;
	double delta_x = (display->getWidth() / 2) - Player::xMouse;
	angle_deg = (atan2(delta_y, delta_x) * 180.0000) / 3.1416 - 90;
}

void Player::setMouseCoords(int _xMouse, int _yMouse){
	yMouse = _yMouse;
	xMouse = _xMouse;
}

double Player::getAngle()
{
	return angle_deg;
}

