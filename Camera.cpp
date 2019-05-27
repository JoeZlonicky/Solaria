#include "Camera.h"

Camera::Camera(Display* display) {
	this->display = display;
}

void Camera::update(Sprite* target) {
	x = target->getCenterX();
	y = target->getCenterY();
}

SDL_Rect Camera::apply(SDL_Rect rect) {
	int newX = display->getWidth() / 2 + rect.x - x;
	int newY = display->getHeight() / 2 + rect.y - y;
	SDL_Rect newRect = { newX, newY, rect.w, rect.h };
	return newRect;
}

void Camera::setMap(Map* map) {
	this->map = map;
}

double Camera::getX() {
	return x;
}

double Camera::getY() {
	return y;
}