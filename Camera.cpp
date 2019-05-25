#include "Camera.h"
#include <algorithm>

Camera::Camera(int displayWidth, int displayHeight) : displayWidth(displayWidth), displayHeight(displayHeight) {
}

void Camera::update(Sprite* target) {
	x = target->getCenterX();
	y = target->getCenterY();
}

SDL_Rect Camera::apply(SDL_Rect rect) {
	int newX = displayWidth / 2 + rect.x - x;
	int newY = displayHeight / 2 + rect.y - y;
	SDL_Rect newRect = { newX, newY, rect.w, rect.h };
	return newRect;
}

void Camera::updateMap(Map* newMap) {
	map = newMap;
}

double Camera::getX() {
	return x;
}

double Camera::getY() {
	return y;
}