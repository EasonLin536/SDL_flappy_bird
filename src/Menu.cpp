#include "Menu.h"
#include "Game.h"

Menu::Menu(const char* filename): Page(filename) {
    loadObjects();
};

Menu::~Menu() {
    // free all the buttons...
}

void Menu::loadObjects() {
    // Load the buttons...
    startButton = new Button("picture/start.png", 0, 400);
    startButton->setXPos(Game::SCREEN_WIDTH/2 -startButton->getWidth() -100);
    tutorialButton = new Button("picture/tutorialbutton.png", 0, 400);
    tutorialButton->setXPos(Game::SCREEN_WIDTH/2 +100);
}

void Menu::handleEvent() {
    // If a button is pressed, update data members
    startButton->handleEvent();
    tutorialButton->handleEvent();
}

void Menu::update() {
    // Change the state of the game
    // Change the layout?...
    startButton->update();
    tutorialButton->update();
    if (startButton->isClicked()) { Game::state = Game::GAME_START; }
    if (tutorialButton->isClicked()) { Game::state = Game::GAME_TUTORIAL; }
}

void Menu::render() {
    SDL_RenderCopyEx(Game::renderer, pageTexture, NULL, &pageRect, 0, NULL, SDL_FLIP_NONE);
    startButton->render();
    tutorialButton->render();
}