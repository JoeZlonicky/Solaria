#include "SpaceUI.h"

SpaceUI::SpaceUI(Display* display) : UI(display), xPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), 
		zPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), planetNameLabel("Planet name", "assets/upheavtt.ttf", planetNameFontSize), 
		healthBar("assets/healthBar.png"), healthContainer("assets/healthContainer.png") {
	healthBar.setX((double)display->getWidth() - healthBar.getSize().x - healthBarRight);
	healthBar.setY(healthBarTop);
	healthContainer.setX((double)display->getWidth() - healthContainer.getSize().x);
	xPositionLabel.setPosition(positionLeft, positionXTop);
	zPositionLabel.setPosition(positionLeft, positionZTop);
	planetNameLabel.setCenter((double)display->getWidth() / 2, (double)display->getHeight() - planetNameBottomOffset);
}

void SpaceUI::update(Player* player) {
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenter().x;
	xPositionLabel.setText("x: " + stream.str());
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenter().y;
	zPositionLabel.setText("z: " + stream.str());

	if (showPlanetName) {
		planetDisplayAlpha += planetDisplayAlphaIncrease;
		if (planetDisplayAlpha > 255) {
			planetDisplayAlpha = 255;
		}
		planetNameLabel.setAlpha((int)planetDisplayAlpha);
	}
	else {
		planetDisplayAlpha -= planetDisplayAlphaIncrease;
		if (planetDisplayAlpha < 0) {
			planetDisplayAlpha = 0;
		}
		planetNameLabel.setAlpha((int)planetDisplayAlpha);
	}
}

void SpaceUI::draw() {
	display->draw(&xPositionLabel);
	display->draw(&zPositionLabel);
	display->draw(&planetNameLabel);
	display->draw(&healthContainer);
	display->draw(&healthBar);
}

void SpaceUI::displayPlanetName(std::string name) {
	planetNameLabel.setText(name);
	planetNameLabel.setCenter((double)display->getWidth() / 2, (double)display->getHeight() - planetNameBottomOffset);
	showPlanetName = true;
}

void SpaceUI::hidePlanetName() {
	showPlanetName = false;
}
