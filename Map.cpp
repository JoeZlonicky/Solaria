#include "Map.h"
#include "AssetLoader.h"
#include "RandomGenerator.h"


Map::Map(Player* player) {
	backgroundTexture = AssetLoader::LoadTexture("assets/background.png");
	SDL_QueryTexture(backgroundTexture, NULL, NULL, &backgroundTextureWidth, &backgroundTextureHeight);

	planets.push_back(Planet("Sol 64", "assets/sun.png", 0, 0));
	planets.push_back(Planet("Gera", "assets/rockPlanet.png", 0.00005, 1200));
	planets.push_back(Planet("Eos", "assets/greenPlanet.png", 0.0001, 2000));
	planets.push_back(Planet("Rugar", "assets/redPlanet.png", 0.000075, 2800));

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
				AsteroidType newSize = AsteroidType(asteroids.at(i).getType() - 1);
				double x = asteroids.at(i).getPosition().x;
				double y = asteroids.at(i).getPosition().y;
				asteroids.push_back(Asteroid(newSize, x, y));
				asteroids.push_back(Asteroid(newSize, x, y));
			}
			asteroids.erase(asteroids.begin() + i);
		}

		else {
			double dx = asteroids.at(i).getCenter().x - player->getCenter().x;
			double dy = asteroids.at(i).getCenter().y - player->getCenter().y;
			if (sqrt(dx * dx + dy * dy) > objectDespawnDistance) {
				asteroids.erase(asteroids.begin() + i);
			}
		}
	}
	for (Planet& planet : planets) {
		planet.update();
	}

	for (unsigned int i = 0; i < enemyFighters.size(); ++i)
	{
		enemyFighters.at(i)->update(&enemyProjectiles);
	}

	for (unsigned int i = 0; i < projectiles.size(); ++i) {
		projectiles.at(i)->update();
		double dx = projectiles.at(i)->getCenter().x - player->getCenter().x;
		double dy = projectiles.at(i)->getCenter().y - player->getCenter().y;
		if (sqrt(dx * dx + dy * dy) > objectDespawnDistance) {
			projectiles.erase(projectiles.begin() + i);
		}
		else {
			bool projectileDeleted = false;
			for (Asteroid& asteroid : asteroids) {
				if (projectiles.at(i)->collides(asteroid)) {
					asteroid.hit();
					projectiles.erase(projectiles.begin() + i);
					projectileDeleted = true;
					break;
				}
			}

			if (projectileDeleted) {
				break;
			}

			for (EnemyFighter* enemyFighter : enemyFighters) {
				if (projectiles.at(i)->collides(*enemyFighter)) {
					enemyFighter->takeDamage(2);
					projectiles.erase(projectiles.begin() + i);
					projectileDeleted = true;
					break;
				}
			}
		}

	}

	for (unsigned int i = 0; i < enemyProjectiles.size(); i++) {
		enemyProjectiles.at(i)->update();
		double dx = enemyProjectiles.at(i)->getCenter().x - player->getCenter().x;
		double dy = enemyProjectiles.at(i)->getCenter().y - player->getCenter().y;
		if (sqrt(dx * dx + dy * dy) > objectDespawnDistance) {
			enemyProjectiles.erase(enemyProjectiles.begin() + i);
		}

		if (enemyProjectiles.at(i)->collides(*player)) {
			enemyProjectiles.erase(enemyProjectiles.begin() + i);
			printf("Projectile hit Player");
		}
	}
}
		


std::vector<Asteroid>* Map::getAsteroids() {
	return &asteroids;
}

std::vector<Planet>* Map::getPlanets() {
	return &planets;
}

std::vector<Projectile*>* Map::getProjectiles() {
	return &projectiles;
}

std::vector<Projectile*>* Map::getEnemyProjectiles()
{
	return &enemyProjectiles;
}

std::vector<EnemyFighter*>* Map::getEnemyFighters()
{
	return &enemyFighters;
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
	double x = cos(angle) * asteroidSpawnDistance + player->getCenter().x;
	double y = sin(angle) * asteroidSpawnDistance + player->getCenter().y;
	Asteroid newAsteroid = Asteroid();
	newAsteroid.setCenter(x, y);
	asteroids.push_back(newAsteroid);
}
