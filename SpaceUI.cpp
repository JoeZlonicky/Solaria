#include "SpaceUI.h"

SpaceUI::SpaceUI(Display* display) : xPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), 
		zPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), healthBar("assets/healthBar.png"), 
		healthContainer("assets/healthContainer.png") {
	this->display = display;
	healthBar.setX((double)display->getWidth() - healthBar.getWidth() - healthBarRight);
	healthBar.setY(healthBarTop);
	healthContainer.setX((double)display->getWidth() - healthContainer.getWidth());
	xPositionLabel.setPosition(positionLeft, positionXTop);
	zPositionLabel.setPosition(positionLeft, positionZTop);
}

void SpaceUI::update(Player* player) {
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenterX();
	xPositionLabel.updateText("x: " + stream.str());
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenterY();
	zPositionLabel.updateText("z: " + stream.str());
}

void SpaceUI::draw(Display* display) {
	display->draw(&xPositionLabel);
	display->draw(&zPositionLabel);
	display->draw(&healthContainer);
	display->draw(&healthBar);
}
