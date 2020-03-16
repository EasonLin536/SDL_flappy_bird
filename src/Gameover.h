#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "GameObject.h"
#include "Page.h"
#include "Button.h"

class Gameover: public Page
{
public:
    Gameover(const char*);
    ~Gameover();

    virtual void loadObjects();
    virtual void handleEvent();
    virtual void update();
    virtual void render();

private:
    Button* restartButton;
    Button* quitButton;
};

#endif