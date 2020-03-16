#include "Tutorial.h"
#include "Game.h"

Tutorial::Tutorial(const char* filename): Page(filename) {
    loadObjects();
};

Tutorial::~Tutorial() {
    // free all the buttons...
}

void Tutorial::loadObjects() {
    // Load the buttons...
    homeButton = new Button("home.png", 30, 30);
    homeButton->setWidth(50);
    homeButton->setHeight(50);
}

void Tutorial::handleEvent() {
    // If a button is pressed, update data members
    homeButton->handleEvent();
}

void Tutorial::update() {
    // Change the state of the game
    // Change the layout?...
    homeButton->update();
    if (homeButton->isClicked()) { Game::state = Game::GAME_HOME; }
}

void Tutorial::render() {
    SDL_RenderCopyEx(Game::renderer, pageTexture, NULL, &pageRect, 0, NULL, SDL_FLIP_NONE);
    homeButton->render();
}