#include "Bird.h"
#include "Pipe.h"

Bird::Bird(const char* filename, int x, int y) : GameObject(filename, x, y) {
	// Adjust pipe dimensions
    double multi = (double)BIRD_WIDTH / (double)width;
    width = BIRD_WIDTH;
    height *= multi;
    objRect = {x, y, width, height};
    // Simulate falling effect
    fall_t = 0;
};

void Bird::handleEvent() {
    //If a key was pressed
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym == SDLK_UP) {
        fall_t = -BIRD_VEL;
    }
}

void Bird::update() {
    if (yPos < 0) { yPos = 0; }
    fall();
    if ((yPos + height > Game::SCREEN_HEIGHT) || Game::checkCollision(objRect, Pipe::topRect) || Game::checkCollision(objRect, Pipe::bottomRect)) {
		Game::state = Game::GAME_OVER;
    }
	objRect.y = yPos;
}

void Bird::render() {
	SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &objRect, 0, NULL, SDL_FLIP_NONE);
}

void Bird::fall() {
    yPos += GRAVITY * fall_t;
    fall_t++;
}