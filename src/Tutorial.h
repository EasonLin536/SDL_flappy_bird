#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include "GameObject.h"
#include "Page.h"
#include "Button.h"

class Tutorial: public Page
{
public:
    Tutorial(const char*);
    ~Tutorial();

    virtual void loadObjects();
    virtual void handleEvent();
    virtual void update();
    virtual void render();

private:
    Button* homeButton;
};

#endif