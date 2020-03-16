#include "Game.h"

using namespace std;

Game* game = NULL;
const int Game::SCREEN_WIDTH = 800;
const int Game::SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    game = new Game;

    game->init("Flappy Bird Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}