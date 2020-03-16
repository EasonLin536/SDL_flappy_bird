#ifndef _PAGE_H_
#define _PAGE_H_

#include "Game.h"
#include "TextureManager.h"

class Page
{
public:
    Page(const char*);
    ~Page() { TextureManager::free(pageTexture); }
    
    virtual void loadObjects() = 0;
    virtual void handleEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    SDL_Texture* pageTexture;
    SDL_Rect pageRect;
};

#endif