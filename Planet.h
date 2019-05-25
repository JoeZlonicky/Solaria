#pragma once
#include <string>
#include "Sprite.h"

class Planet : public Sprite {
public:
	Planet(std::string name, std::string imagePath, int x, int y);

private:
	std::string name;
};

