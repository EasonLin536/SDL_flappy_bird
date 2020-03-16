#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Game.h"
#include "TextureManager.h"

// Use for inheritance
class GameObject 
{
public:
    // Each derived class shares the same
    GameObject(const char*, int, int);
    ~GameObject() { TextureManager::free(objTexture); };

    int getWidth() { return width; }
    int getHeight() { return height; }
    void setXPos(int x) { xPos = x; }
    void setYPos(int y) { yPos = y; }
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }

    // Each object has different ways of handle event and update
    virtual void handleEvent() = 0;
    virtual void update() = 0;    
    virtual void render() = 0;

protected:
    // position of the object
    int xPos;
    int yPos;
    int width;
    int height;
    SDL_Texture* objTexture;
    SDL_Rect objRect;
};

#endif