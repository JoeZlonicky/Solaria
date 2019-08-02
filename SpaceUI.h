#pragma once
#include <iomanip>
#include <sstream>

#include "UI.h"
#include "Display.h"
#include "Player.h"
#include "Label.h"
#include "Sprite.h"


class SpaceUI : public UI {
public:
	SpaceUI(Display* display, Map* map);

	void update(Player* player);
	void draw();

	void displayPlanetName(std::string name);
	void hidePlanetName();

private:
	const int positionFontSize = 48;
	const int positionLeft = 10;
	const int positionXTop = 4;
	const int positionZTop = 36;
	const int planetNameFontSize = 100;
	const int planetNameBottomOffset = 100;
	const int ammoFontSize = 64;
	const int ammoRight = 8;
	const int ammoTop = 75;
	const int healthBarRight = 8;
	const int healthBarTop = 8;
	const double planetDisplayAlphaIncrease = 2;

	Map* map = nullptr;
	Label xPositionLabel;
	Label zPositionLabel;
	Label planetNameLabel;
	Label ammoCounter;
	Sprite healthBar;
	Sprite healthContainer;
	std::stringstream stream;
	bool showPlanetName = false;
	double planetDisplayAlpha = 0;
};
