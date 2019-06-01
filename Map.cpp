#include "Map.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Map::Map(Player* player) {
	backgroundTexture = AssetLoader::LoadTexture("assets/background.png");
	SDL_QueryTexture(backgroundTexture, NULL, NULL, &backgroundTextureWidth, &backgroundTextureHeight);

	planets.push_back(Planet("assets/sun.png", 0, 0));
	planets.push_back(Planet("assets/rockPlanet.png", 0.00005, 1200));
	planets.push_back(Planet("assets/greenPlanet.png", 0.0001, 2000));
	planets.push_back(Planet("assets/redPlanet.png", 0.000075, 2800));

	this->player = player;
}

void Map::update() {
	while (asteroids.size() < maxNumberOfAsteroids) {
		spawnAsteroid();
	}
	for (unsigned int i = 0; i < asteroids.size(); ++i) {
		asteroids.at(i).update();
		if (asteroids.at(i).shouldDestroy()) {
			if (asteroids.at(i).breaksSmaller()) {
				AsteroidSize newSize = AsteroidSize(asteroids.at(i).getSize() - 1);
				double x = asteroids.at(i).getX();
				double y = asteroids.at(i).getY();
				asteroids.push_back(Asteroid(newSize, x, y));
				asteroids.push_back(Asteroid(newSize, x, y));
			}
			asteroids.erase(asteroids.begin() + i);
		}
		else {
			double dx = asteroids.at(i).getCenterX() - player->getCenterX();
			double dy = asteroids.at(i).getCenterY() - player->getCenterY();
			if (sqrt(dx * dx + dy * dy) > objectDespawnDistance) {
				asteroids.erase(asteroids.begin() + i);
			}
		}
	}
	for (Planet& planet : planets) {
		planet.update();
	}
	for (unsigned int i = 0; i < projectiles.size(); ++i) {
		projectiles.at(i).update();
		double dx = projectiles.at(i).getCenterX() - player->getCenterX();
		double dy = projectiles.at(i).getCenterY() - player->getCenterY();
		if (sqrt(dx * dx + dy * dy) > objectDespawnDistance) {
			projectiles.erase(projectiles.begin() + i);
		}
	}
}

std::vector<Asteroid>* Map::getAsteroids() {
	return &asteroids;
}

std::vector<Planet>* Map::getPlanets() {
	return &planets;
}

std::vector<Projectile>* Map::getProjectiles() {
	return &projectiles;
}

SDL_Texture* Map::getBackgroundTexture() {
	return backgroundTexture;
}

int Map::getBackgroundTextureWidth() {
	return backgroundTextureWidth;
}

int Map::getBackgroundTextureHeight() {
	return backgroundTextureHeight;
}

void Map::spawnAsteroid() {
	double angle = RandomGenerator::randint(0, 355) * 3.14159 / 180;
	double x = cos(angle) * asteroidSpawnDistance + player->getCenterX();
	double y = sin(angle) * asteroidSpawnDistance + player->getCenterY();
	Asteroid newAsteroid = Asteroid();
	newAsteroid.setCenter(x, y);
	asteroids.push_back(newAsteroid);
}
