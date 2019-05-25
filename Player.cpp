#include "Player.h"
#include "Game.h"

Player::Player(std::string filePath, int x, int y) : Sprite(filePath, x, y) {
	speed = 0.5;

}

void Player::move(double movementX, double movementY){
	Sprite::moveX(movementX);
	Sprite::moveY(movementY);
}

void Player::update(){
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_W]) {
		move(0, -speed);
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		move(-speed, 0);
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		move(0, speed);
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		move(speed, 0);
	}

}
