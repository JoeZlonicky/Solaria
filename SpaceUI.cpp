#include "SpaceUI.h"

SpaceUI::SpaceUI(Display* display) : xPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), 
		zPositionLabel("0", "assets/upheavtt.ttf", positionFontSize), healthBar("assets/healthBar.png"), 
		healthContainer("assets/healthContainer.png") {
	this->display = display;
	healthBar.setX((double)display->getWidth() - healthBar.getSize().x - healthBarRight);
	healthBar.setY(healthBarTop);
	healthContainer.setX((double)display->getWidth() - healthContainer.getSize().x);
	xPositionLabel.setPosition(positionLeft, positionXTop);
	zPositionLabel.setPosition(positionLeft, positionZTop);
}

void SpaceUI::update(Player* player) {
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenter().x;
	xPositionLabel.updateText("x: " + stream.str());
	stream.str("");
	stream << std::fixed << std::setprecision(2) << player->getCenter().y;
	zPositionLabel.updateText("z: " + stream.str());
}

void SpaceUI::draw(Display* display) {
	display->draw(&xPositionLabel);
	display->draw(&zPositionLabel);
	display->draw(&healthContainer);
	display->draw(&healthBar);
}
