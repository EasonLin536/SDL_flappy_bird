#include "BackGround.h"

void BackGround::update() {
	if (scrollingOffset < -width) { scrollingOffset = 0; }
    bg1 = {scrollingOffset, 0, width, height};
    bg2 = {scrollingOffset + width, 0, width, height};
    scrollingOffset -= SCROLL_VEL;
}

void BackGround::render() {
    //Render background
    SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &bg1, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &bg2, 0, NULL, SDL_FLIP_NONE);
}