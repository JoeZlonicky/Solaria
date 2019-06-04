#include "Camera.h"

Camera::Camera(Display* display) {
	this->display = display;
}

void Camera::update(Sprite* target) {
	x = target->getCenter().x;
	y = target->getCenter().y;
}

SDL_Rect Camera::apply(SDL_Rect rect) {
	int newX = (int)(display->getWidth() / 2 + rect.x - x);
	int newY = (int)(display->getHeight() / 2 + rect.y - y);
	SDL_Rect newRect = { newX, newY, rect.w, rect.h };
	return newRect;
}

Vector Camera::apply(Vector vec) {
	return Vector(display->getWidth() / 2 + vec.x - x, display->getHeight() / 2 + vec.y - y);
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