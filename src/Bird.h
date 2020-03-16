#ifndef _BIRD_H_
#define _BIRD_H_

#include "Game.h"
#include "GameObject.h"

class Bird: public GameObject
{
public:
    Bird(const char*, int, int);

	virtual void handleEvent();
	virtual void update();
	virtual void render();

private:
	const int BIRD_WIDTH = 60;
    const int BIRD_VEL = 15;
    const double GRAVITY = 0.2;
    int fall_t;

    void fall();
};

#endif