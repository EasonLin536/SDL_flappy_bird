#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_
#include "Game.h"

class TextureManager 
{
public:
    static SDL_Texture* loadTexture(const char*, int&, int&);
    static void free(SDL_Texture*);
private:
};

#endif