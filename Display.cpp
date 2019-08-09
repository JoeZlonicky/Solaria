#include "Display.h"

#include <SDL_image.h>
#include "AssetLoader.h"

// Create a fullscreen display
Display::Display(std::string title) : lastTick(0) {
	SDL_DisplayMode displayMode;
	if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
		printf("Failed to get display mode. Error: %s\n", SDL_GetError());
		return;
	}
	init(title, displayMode.w, displayMode.h, SDL_WINDOW_FULLSCREEN);
}

// Create a windowed display
Display::Display(std::string title, int windowWidth, int windowHeight) : lastTick(0) {
	init(title, windowWidth, windowHeight, 0);
}

// Create window and initialize variables
void Display::init(std::string title, int windowWidth, int windowHeight, int fullscreenFlag) {
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		windowWidth, windowHeight, SDL_WINDOW_SHOWN | fullscreenFlag);
	if (window == NULL) {
		printf("Failed to create window. Error: %s\n", SDL_GetError());
		return;
	}
	setIcon();
	SDL_ShowCursor(SDL_DISABLE);
	createRenderer();
	SDL_RenderSetLogicalSize(renderer, resolutionWidth, resolutionHeight);
	cursorTexture = AssetLoader::LoadTexture("assets/crosshair.png");
}

// Create the renderer
void Display::createRenderer() {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Failed to create renderer. Error: %s\n", SDL_GetError());
	}
	AssetLoader::init(renderer);
}

// Clear the display with the clear color
void Display::clear() {
	SDL_SetRenderDrawColor(renderer, clearR, clearG, clearB, 255);
	SDL_RenderClear(renderer);
}

// Set the color to clear the display with
void Display::setClearColor(Uint8 r, Uint8 g, Uint8 b) {
	clearR = r;
	clearG = g;
	clearB = b;
}

// Draw a sprite to the display, opitionally with a camera
void Display::draw(Sprite* sprite, Camera* camera) {
	SDL_Rect rect = sprite->getRect();
	if (camera != nullptr) {
		rect = camera->apply(rect);
	}
	SDL_RenderCopyEx(renderer, sprite->getTexture(), NULL, &rect, sprite->getRotation(), NULL, sprite->getFlip());
}

// Draw the bounding box of a sprite
void Display::drawCollider(Sprite* sprite, Camera* camera) {
	std::vector<Vector> points = sprite->getBoundingPoints();
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	if (camera != nullptr) {
		for (Vector& vec : points) {
			vec = camera->apply(vec);
		}
	}
	SDL_RenderDrawLine(renderer, (int)points[0].x, (int)points[0].y, (int)points[1].x, (int)points[1].y);
	SDL_RenderDrawLine(renderer, (int)points[1].x, (int)points[1].y, (int)points[2].x, (int)points[2].y);
	SDL_RenderDrawLine(renderer, (int)points[2].x, (int)points[2].y, (int)points[3].x, (int)points[3].y);
	SDL_RenderDrawLine(renderer, (int)points[3].x, (int)points[3].y, (int)points[0].x, (int)points[0].y);
}

// Draw the contents of a map
void Display::draw(Map* map, Camera* camera) {
	int textureWidth = map->getBackgroundTextureWidth();
	int textureHeight = map->getBackgroundTextureHeight();
	int cameraX = -(int)camera->getPosition().x % textureWidth;
	int cameraY = -(int)camera->getPosition().y % textureHeight;
	SDL_Rect rect;
	for(int x = cameraX - resolutionWidth; x < resolutionWidth; x += textureWidth) {
		for (int y = cameraY - resolutionHeight; y < resolutionHeight; y += textureHeight) {
			rect = { x, y, textureWidth, textureHeight };
			SDL_RenderCopy(renderer, map->getBackgroundTexture(), NULL, &rect);
		}
	}
	
	for (Planet& planet : *map->getPlanets()) {
		draw(&planet, camera);
	}
	for (Asteroid& asteroid : *map->getAsteroids()) {
		draw(&asteroid, camera);
	}
	for (Projectile* projectile : *map->getProjectiles()) {
		draw(projectile, camera);
	}
	for (Projectile* enemyProjectile : *map->getEnemyProjectiles()) {
		draw(enemyProjectile, camera);
	}
	for (EnemyFighter* enemyFighter : *map->getEnemyFighters()) {
		draw(enemyFighter, camera);
	}
	
}

// Draw the cursor on the display
void Display::drawCursor() {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	
	double scaleX = (double)resolutionWidth / windowWidth;
	double scaleY = (double)resolutionHeight / windowHeight;
	SDL_Rect rect = { (int)(mouseX * scaleX - cursorSize / 2), (int)(mouseY * scaleY- cursorSize / 2), cursorSize, cursorSize };
	SDL_RenderCopy(renderer, cursorTexture, NULL, &rect);
}

// Set the icon of the window
void Display::setIcon() {
	SDL_Surface* image = IMG_Load("assets/icon.png");
	if (image == NULL) {
		printf("Failed to load icon. Error: %s\n", IMG_GetError());
	}
	SDL_SetWindowIcon(window, image);
}

// Update display and handle fps
void Display::update() {
	SDL_RenderPresent(renderer);

	Uint32 deltaTick = SDL_GetTicks() - lastTick;
	Uint32 expectedTick = 1000 / fps;
	fpsTracker += deltaTick;
	if (deltaTick < expectedTick) {
		SDL_Delay(expectedTick - deltaTick);
		fpsTracker += expectedTick - deltaTick;
	}
	lastTick = SDL_GetTicks();
	++frameCount;
	while (fpsTracker > 1000) {
		printf("FPS: %.0f\n", (double)frameCount / fpsTracker * 1000);
		fpsTracker -= 1000;
		frameCount = 0;
	}
}

// Free the window and renderer
void Display::free() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Display::getRenderer() {
	return renderer;
}

SDL_Window* Display::getWindow()
{
	return window;
}

int Display::getWidth() {
	return resolutionWidth;
}

int Display::getHeight() {
	return resolutionHeight;
}

int Display::getWindowWidth() {
	return windowWidth;
}

int Display::getWindowHeight() {
	return windowHeight;
}


