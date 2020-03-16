#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "GameObject.h"

class Button: public GameObject
{
public:
    Button(const char*, int, int);

    virtual void handleEvent();
	virtual void update();
	virtual void render();
    bool isClicked() { 
        if (click) { click = false; return true; }
        return click; 
    }

private:
    const int BUTTON_WIDTH = 100;
    const int BUTTON_HEIGHT = 100;
    bool click;
};

#endif