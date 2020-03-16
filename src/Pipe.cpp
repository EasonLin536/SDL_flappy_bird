#include "Pipe.h"
#include "time.h"

SDL_Rect Pipe::topRect;
SDL_Rect Pipe::bottomRect;

Pipe::Pipe(const char* filename_1, const char* filename_2) {
    topPipeTexture = TextureManager::loadTexture(filename_1, width, height);
    bottomPipeTexture = TextureManager::loadTexture(filename_2, width, height);
    // Adjust pipe dimensions
    double multi = (double)PIPE_WIDTH / (double)width;
    width = PIPE_WIDTH;
    height *= multi;

    // Initialize
    xPos = Game::SCREEN_WIDTH + 300;
    srand(time(NULL));
}

void Pipe::update() {
    if (xPos + PIPE_WIDTH < 0) { refresh = true; }
    else { refresh = false; }

    // No pipe on the screen, generate one
    if (refresh) {
        xPos = Game::SCREEN_WIDTH;
        getGapYPos();   // Randomize yPos
    }
    // If there is a pair of pipe on the screen
    else { xPos -= PIPE_VEL; }

    topRect = {xPos, yPos-height, width, height};
    bottomRect = {xPos, yPos+OPENING_GAP, width, height};
}

void Pipe::render() {
    SDL_RenderCopyEx(Game::renderer, topPipeTexture, NULL, &topRect, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(Game::renderer, bottomPipeTexture, NULL, &bottomRect, 0, NULL, SDL_FLIP_NONE);
}

void Pipe::getGapYPos() {
    int top_limit = 20;
    int bottom_limit = Game::SCREEN_HEIGHT - OPENING_GAP - 20;

    yPos = rand() % (bottom_limit - top_limit) + top_limit;
}