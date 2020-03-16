#include "Button.h"
#include "Game.h"

Button::Button(const char* filename, int x, int y): GameObject(filename, x, y) {
	click = false;
	width = BUTTON_WIDTH;
	height = BUTTON_HEIGHT;
}

void Button::handleEvent() {
	// When clicking 
	if (Game::event.type == SDL_MOUSEBUTTONDOWN) {
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		if( x < xPos ) { click = false; }
		else if( x > xPos + BUTTON_WIDTH ) { click = false; }
		else if( y < yPos )	{ click = false; }
		else if( y > yPos + BUTTON_HEIGHT ) { click = false; }
		else { click = true; }
	}
}

void Button::update() {
	// If want to change button position, color, ....
	objRect = {xPos, yPos, width, height};
}

void Button::render() {
	SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &objRect, 0, NULL, SDL_FLIP_NONE);
}