#include "Gameover.h"
#include "Game.h"

Gameover::Gameover(const char* filename): Page(filename) {
    loadObjects();
};

Gameover::~Gameover() {
    // free all the buttons...
}

void Gameover::loadObjects() {
    // Load the buttons...
    restartButton = new Button("restart.png", 0, 400);
    restartButton->setXPos(Game::SCREEN_WIDTH/2 -restartButton->getWidth() -100);
    quitButton = new Button("quit.png", 0, 400);
    quitButton->setXPos(Game::SCREEN_WIDTH/2 +100);
}

void Gameover::handleEvent() {
    // If a button is pressed, update data members
    restartButton->handleEvent();
    quitButton->handleEvent();
}

void Gameover::update() {
    // Change the state of the game
    // Change the layout?...
    restartButton->update();
    quitButton->update();
    if (restartButton->isClicked()) { Game::state = Game::GAME_RESTART; }
    if (quitButton->isClicked()) { Game::state = Game::GAME_QUIT; }
}

void Gameover::render() {
    SDL_RenderCopyEx(Game::renderer, pageTexture, NULL, &pageRect, 0, NULL, SDL_FLIP_NONE);
    restartButton->render();
    quitButton->render();
}