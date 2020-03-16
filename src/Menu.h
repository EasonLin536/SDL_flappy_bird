#ifndef _MENU_H_
#define _MENU_H_

#include "GameObject.h"
#include "Page.h"
#include "Button.h"

class Menu: public Page
{
public:
    Menu(const char*);
    ~Menu();

    virtual void loadObjects();
    virtual void handleEvent();
    virtual void update();
    virtual void render();

private:
    Button* startButton;
    Button* tutorialButton;
};

#endif