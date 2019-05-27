#pragma once
#include <vector>
#include "Asteroid.h"
#include "Display.h"
#include "Camera.h"

class AsteroidHandler {
public:
	void update();
	void freeAsteroids();
	void drawAsteroids(Display* display, Camera* camera);
	void addAsteroid(int x, int y);
	std::vector<Asteroid*> getAsteroids();
	
private:
	std::vector<Asteroid*> asteroids = std::vector<Asteroid*>();
};

