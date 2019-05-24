#include "Camera.h"
#include <algorithm>

Camera::Camera(int displayWidth, int displayHeight) : displayWidth(displayWidth), displayHeight(displayHeight) {
}

void Camera::update(Sprite* target) {
	int centerX = target->getX() + target->getWidth() / 2;
	int centerY = target->getY() + target->getHeight() / 2;
	int displayCenterX = displayWidth / 2;
	int displayCenterY = displayHeight / 2;

	x = std::max(0, centerX  - displayCenterX);
	x = std::min(x, map->getWidth());
	y = std::max(0, centerY - displayCenterY);
	y = std::min(y, map->getHeight());
}

SDL_Rect Camera::apply(SDL_Rect rect) {
	SDL_Rect newRect = { rect.x - x, rect.y - y, rect.w, rect.h };
	return newRect;
}

void Camera::updateMap(Map* newMap) {
	map = newMap;
}

int Camera::getX() {
	return x;
}

int Camera::getY() {
	return y;
}