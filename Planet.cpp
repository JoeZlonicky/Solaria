#include "Planet.h"


Planet::Planet(std::string name, std::string imagePath, int x, int y) : Sprite(imagePath, x, y), name(name) {
}
