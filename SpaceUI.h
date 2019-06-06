#pragma once
#include <iomanip>
#include <sstream>
#include "Label.h"
#include "Sprite.h"
#include "Display.h"
#include "Player.h"


class Player;

class SpaceUI {
public:
	SpaceUI(Display* display);

	void update(Player* player);
	void draw(Display* display);

	void displayPlanetName(std::string name);
	void hidePlanetName();

private:
	const int positionFontSize = 48;
	const int positionLeft = 10;
	const int positionXTop = 4;
	const int positionZTop = 28;
	const int planetNameFontSize = 100;
	const int planetNameBottomOffset = 100;
	const int healthBarRight = 8;
	const int healthBarTop = 8;

	const double planetDisplayAlphaIncrease = 2;

	Display* display;
	Label xPositionLabel;
	Label zPositionLabel;
	Label planetNameLabel;
	Sprite healthBar;
	Sprite healthContainer;

	std::stringstream stream;
	bool showPlanetName = false;
	double planetDisplayAlpha = 0;
};
