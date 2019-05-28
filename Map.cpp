#include "Map.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Map::Map(Player* player) {
	backgroundTexture = AssetLoader::LoadTexture("assets/background.png");
	SDL_QueryTexture(backgroundTexture, NULL, NULL, &backgroundTextureWidth, &backgroundTextureHeight);

	planets.push_back(Planet("assets/sun.png", 0, 0));
	planets.push_back(Planet("assets/rockPlanet.png", 0.00005, 400));
	planets.push_back(Planet("assets/greenPlanet.png", 0.0001, 800));
	planets.push_back(Planet("assets/redPlanet.png", 0.000075, 1200));

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
			asteroids.at(i).free();
			asteroids.erase(asteroids.begin() + i);
		}
		else {
			double dx = asteroids.at(i).getCenterX() - player->getCenterX();
			double dy = asteroids.at(i).getCenterY() - player->getCenterY();
			if (sqrt(dx * dx + dy * dy) > asteroidDespawnDistance) {
				asteroids.erase(asteroids.begin() + i);
			}
		}
	}
	for (Planet& planet : planets) {
		planet.update();
	}
	for (Projectile& projectile : projectiles) {
		projectile.update();
	}
}

void Map::free() {
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = nullptr;
	for (Asteroid& asteroid : asteroids) {
		asteroid.free();
	}
	for (Planet& planet : planets) {
		planet.free();
	}
	for (Projectile& projectile : projectiles) {
		projectile.free();
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
