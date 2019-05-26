#include "Player.h"
#include "Game.h"

Player::Player(std::string filePath, double x, double y) : Sprite(filePath, x, y) {
	speed = 0.25;

}

void Player::move(double movementX, double movementY){
	Sprite::moveX(movementX);
	Sprite::moveY(movementY);
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_W]) {
		double x, y;
		x = speed * (cos((angle_deg - 90) * 0.0174532925));
		y = speed * (sin((angle_deg - 90) * 0.0174532925));

		move(x, y);
	}
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

