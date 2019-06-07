#pragma once
#include <vector>
#include <SDL.h>

#include "Asteroid.h"
#include "Planet.h"
#include "Player.h"
#include "Projectile.h"

class Player;
class Camera;

class Map {
public:
	Map(Player* player);

	void update();

	std::vector<Asteroid>* getAsteroids();
	std::vector<Planet>* getPlanets();
	std::vector<Projectile*>* getProjectiles();
	SDL_Texture* getBackgroundTexture();
	int getBackgroundTextureWidth();
	int getBackgroundTextureHeight();
	
private:
	void spawnAsteroid();

	const double asteroidSpawnDistance = 1200;
	const unsigned int maxNumberOfAsteroids = 30;
	const double objectDespawnDistance = 1600;

	std::vector<Asteroid> asteroids;
	std::vector<Planet> planets;
	std::vector<Projectile*> projectiles;
	SDL_Texture* backgroundTexture = nullptr;
	Player* player;
	int backgroundTextureWidth;
	int backgroundTextureHeight;
	
};

