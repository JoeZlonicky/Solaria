#include "AsteroidHandler.h"

void AsteroidHandler::update() {
	for (Asteroid* asteroid : asteroids) {
		asteroid->update();
	}
	for (int i = 0; i < asteroids.size(); ++i) {
		if (asteroids.at(i)->shouldDestroy()) {
			if (asteroids.at(i)->breaksSmaller()) {
				asteroids.push_back(new Asteroid(AsteroidSize(asteroids.at(i)->getSize() - 1), asteroids.at(i)->getX(), asteroids.at(i)->getY()));
				asteroids.push_back(new Asteroid(AsteroidSize(asteroids.at(i)->getSize() - 1), asteroids.at(i)->getX(), asteroids.at(i)->getY()));
			}
			asteroids.at(i)->free();
			asteroids.erase(asteroids.begin() + i);
		}
	}
}

void AsteroidHandler::freeAsteroids() {
	for (Asteroid* asteroid : asteroids) {
		asteroid->free();
	}
}

void AsteroidHandler::drawAsteroids(Display* display, Camera* camera) {
	for (Asteroid* asteroid : asteroids) {
		display->draw(asteroid, camera);
	}
}

void AsteroidHandler::addAsteroid(int x, int y) {
	asteroids.push_back(new Asteroid(x, y));
}

std::vector<Asteroid*> AsteroidHandler::getAsteroids() {
	return asteroids;
}
