#pragma once
#include <vector>
#include "UI.h"

class UI;
class Game;

class UIManager {
public:
	void draw();
	void update();
	UI* getFocusedLayer();
	void addLayer(UI* layer);
	void removeTopLayer();
	bool pauseGame();

private:
	std::vector<UI*> uiLayers;
};

