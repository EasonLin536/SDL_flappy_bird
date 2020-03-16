#include "Page.h"

Page::Page(const char* filename) {
    int tmp1, tmp2;
    pageTexture = TextureManager::loadTexture(filename, tmp1, tmp2);
    pageRect = {0, 0, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT};
}