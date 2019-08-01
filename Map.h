#pragma once
#include <SDL.h>
#include <vector>
#include "Asteroid.h"
#include "Planet.h"
#include "Player.h"
#include "EnemyFighter.h"

class Player;
class EnemyFighter;
class Camera;

class Map {
public:
	Map(Player* player);

	void update();

	std::vector<Asteroid>* getAsteroids();
	std::vector<Planet>* getPlanets();
	std::vector<Projectile*>* getProjectiles();
	std::vector<Projectile*>* getEnemyProjectiles();
	std::vector<EnemyFighter*>* getEnemyFighters();
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
	std::vector<Projectile*> enemyProjectiles;
	std::vector<EnemyFighter*> enemyFighters;
	SDL_Texture* backgroundTexture = nullptr;
	Player* player;
	int backgroundTextureWidth;
	int backgroundTextureHeight;
	
};

