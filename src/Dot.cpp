#include "Dot.h"

void Dot::handleEvent()
{
    //If a key was pressed
	if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0) {
        //Adjust the velocity
        switch (Game::event.key.keysym.sym) {
            case SDLK_UP:
                yVel -= DOT_VEL; break;
            case SDLK_DOWN:
                yVel += DOT_VEL; break;
            case SDLK_LEFT:
                xVel -= DOT_VEL; break;
            case SDLK_RIGHT:
                xVel += DOT_VEL; break;
        }
    }
    //If a key was released
    else if (Game::event.type == SDL_KEYUP && Game::event.key.repeat == 0) {
        //Adjust the velocity
        switch (Game::event.key.keysym.sym) {
            case SDLK_UP: 
                yVel += DOT_VEL; break;
            case SDLK_DOWN: 
                yVel -= DOT_VEL; break;
            case SDLK_LEFT: 
                xVel += DOT_VEL; break;
            case SDLK_RIGHT: 
                xVel -= DOT_VEL; break;
        }
    }
}

void Dot::update()
{
    //Move the dot left or right
    xPos += xVel;
	objRect.x = xPos;
    //If the dot collided or went too far to the left or right
    // if ((xPos < 0) || (xPos + DOT_WIDTH > Game::SCREEN_WIDTH) || Game::checkCollision(objRect, Game::wall)) {
    if ((xPos < 0) || (xPos + DOT_WIDTH > Game::SCREEN_WIDTH)) {
        //Move back
        xPos -= xVel;
		objRect.x = xPos;
    }

    //Move the dot up or down
    yPos += yVel;
	objRect.y = yPos;
    //If the dot collided or went too far up or down
    // if ((yPos < 0) || (yPos + DOT_HEIGHT > Game::SCREEN_HEIGHT) || Game::checkCollision(objRect, Game::wall)) {
    if ((yPos < 0) || (yPos + DOT_HEIGHT > Game::SCREEN_HEIGHT)) {
        //Move back
        yPos -= yVel;
		objRect.y = yPos;
    }
}

void Dot::render() {
	//Render to screen
	SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &objRect, 0, NULL, SDL_FLIP_NONE);
}
