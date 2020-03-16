#ifndef _PIPE_H_
#define _PIPE_H_

#include "Game.h"
#include "TextureManager.h"

class Pipe
{
public:
    Pipe(const char*, const char*);
    ~Pipe() { TextureManager::free(topPipeTexture); TextureManager::free(bottomPipeTexture); }
    void update();
    void render();

    static SDL_Rect topRect;
    static SDL_Rect bottomRect;

private:   
    const int OPENING_GAP = 150;
    const int PIPE_WIDTH = 80;
    const int PIPE_VEL = 5;
    
    int xPos, yPos;                 // Position of the gap
    int width, height;
    
    bool refresh = false;         // A pair of pipe is refresh
    
    SDL_Texture* topPipeTexture;
    SDL_Texture* bottomPipeTexture;


    void getGapYPos();
};

#endif