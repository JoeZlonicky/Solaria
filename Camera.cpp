#include "Camera.h"

Camera::Camera(Display* display) {
	this->display = display;
}

// Update the location of the camera
void Camera::update(Sprite* target) {
	position = target->getCenter();
}

// Get position based off camera
SDL_Rect Camera::apply(SDL_Rect rect) {
	int newX = (int)(display->getWidth() / 2 + rect.x - position.x);
	int newY = (int)(display->getHeight() / 2 + rect.y - position.y);
	SDL_Rect newRect = { newX, newY, rect.w, rect.h };
	return newRect;
}

// Get posiiton based off camera
Vector Camera::apply(Vector vec) {
	return Vector(display->getWidth() / 2 + vec.x - position.x,
		display->getHeight() / 2 + vec.y - position.y);
}

Vector Camera::getPosition() {
	return position;
}