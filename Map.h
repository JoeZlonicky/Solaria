#pragma once
#include <SDL.h>
#include <vector>
#include "Asteroid.h"
#include "Planet.h"
#include "Player.h"

class Player;

class Map {
public:
	Map(Player* player);

	void update();
	void free();
	std::vector<Asteroid> getAsteroids();
	std::vector<Planet> getPlanets();
	SDL_Texture* getBackgroundTexture();
	int getBackgroundTextureWidth();
	int getBackgroundTextureHeight();
	
private:
	void spawnAsteroid();

	std::vector<Asteroid> asteroids;
	std::vector<Planet> planets;
	SDL_Texture* backgroundTexture = nullptr;
	Player* player;
	int backgroundTextureWidth;
	int backgroundTextureHeight;
	double asteroidSpawnDistance = 750;
	double asteroidDespawnDistance = 1200;
	unsigned int maxNumberOfAsteroids = 10;
};

