#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "Game.h"
#include "GameObject.h"

class BackGround: public GameObject 
{
public:
    BackGround(const char* filename, int x, int y) : GameObject(filename, x, y) {
        scrollingOffset = 0;
        // Adjust background dimensions to fit the window
        double multi = (double)Game::SCREEN_HEIGHT / (double)height;
        height = Game::SCREEN_HEIGHT;
        width *= multi;
    };
	//Takes key presses and adjusts the dot's velocity
	virtual void handleEvent() {};
	//Moves the dot
	virtual void update();
    // Repeatedly render background
    virtual void render();

private:
    const int SCROLL_VEL = 3;
    int scrollingOffset;
    // Create scrolling effect
    SDL_Rect bg1, bg2;
};

#endif