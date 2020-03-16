#include "Game.h"
#include "GameObject.h"

class Dot: public GameObject
{
public:
    Dot(const char* filename, int x, int y) : GameObject(filename, x, y) {
        xVel = yVel = 0;
		objRect = {x, y, DOT_WIDTH, DOT_HEIGHT};
		// objRect = {x, y, width, height};
    };
	//Takes key presses and adjusts the dot's velocity
	virtual void handleEvent();
	//Moves the dot
	virtual void update();
	// Render the dot
	virtual void render();

private:
    const int DOT_VEL = 10;
	const int DOT_WIDTH = 30;
	const int DOT_HEIGHT = 30;
	//The velocity of the dot
	int xVel, yVel;
};