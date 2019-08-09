#include "UIManager.h"

void UIManager::draw() {
	for (auto &layer : uiLayers) {
		layer->draw();
	}
}

void UIManager::update() {
	for (auto &layer : uiLayers) {
		layer->update();
	}
}

UI* UIManager::getFocusedLayer() {
	if (uiLayers.size() > 0) {
		return uiLayers.back();
	}
	return nullptr;
}

void UIManager::addLayer(UI* layer) {
	uiLayers.push_back(layer);
}

void UIManager::removeTopLayer() {
	uiLayers.pop_back();
}

bool UIManager::pauseGame() {
	return getFocusedLayer()->pausesGame();
}
