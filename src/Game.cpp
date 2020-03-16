#include "Game.h"
#include "BackGround.h"
#include "Pipe.h"
#include "Bird.h"
#include "Menu.h"
#include "Tutorial.h"
#include "Gameover.h"

SDL_Renderer* Game::renderer = NULL;
SDL_Event Game::event;
int Game::state;

// Define game objects pointer//////////////////////
BackGround* background;
Pipe* pipe;
Bird* bird;
Menu* menu;
Tutorial* tutorial;
Gameover* gameover;
////////////////////////////////////////////////////

Game::Game() {
	state = GAME_HOME;
	isRunning = false;
}

Game::~Game() {}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flag = 0;
    if (fullscreen) { flag = SDL_WINDOW_FULLSCREEN; }
    
    // Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cerr << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		isRunning = false;
	}
    else {
		// Create window
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flag);
		if (window == NULL) {
			cerr << "Window could not be created! SDL Error:" << SDL_GetError() << endl;
			isRunning = false;
		}	
        else {
			// Create vsynced renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL) {
				cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				isRunning = false;
			}	
            else {
				// Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
        isRunning = true;
	}
	// New game objects that defined in the beginning of this code//////////////
	menu = new Menu("picture/menu.jpg");
	tutorial = new Tutorial("picture/Tutorial.png");
	background = new BackGround("picture/background.png", 0, 0);
	pipe = new Pipe("picture/pipe_top.png", "picture/pipe_bottom.png");
	bird = new Bird("picture/bird_1.png", 40, 40);
	gameover = new Gameover("picture/gameover.jpg");
	////////////////////////////////////////////////////////////////////////////
}
    
void Game::handleEvents() {
    while (SDL_PollEvent(&Game::event) != 0) {
        if (Game::event.type == SDL_QUIT) { isRunning = false; }
        // Game objects handleEvent()
		if (state == GAME_HOME) { menu->handleEvent(); }
		if (state == GAME_TUTORIAL) { tutorial->handleEvent(); }
		if (state == GAME_START) { bird->handleEvent(); }
		if (state == GAME_OVER) { gameover->handleEvent(); }
    }
}

void Game::update() {
	// Game objects update()
	if (state == GAME_HOME) { menu->update(); }
	if (state == GAME_TUTORIAL) { tutorial->update(); }
	if (state == GAME_START) {
		background->update();
		pipe->update();
		bird->update();
	}
	if (state == GAME_OVER) { gameover->update(); }
	if (state == GAME_RESTART) { restart(); }
	if (state == GAME_QUIT) { isRunning = false; }
}

void Game::render() {
	SDL_RenderClear(renderer);
	// Game objects render on screen
	if (state == GAME_HOME) { menu->render(); }
	if (state == GAME_TUTORIAL) { tutorial->render(); }
	if (state == GAME_START) { 
		background->render();
		pipe->render();
		bird->render(); 
	}	
	if (state == GAME_OVER) { gameover->render(); }

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    // Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::restart() {
	delete background;
	delete pipe;
	delete bird;
	background = new BackGround("picture/background.png", 0, 0);
	pipe = new Pipe("picture/pipe_top.png", "picture/pipe_bottom.png");
	bird = new Bird("picture/bird_1.png", 40, 40);
	state = GAME_START;
}

bool Game::checkCollision(SDL_Rect a, SDL_Rect b) {
    // The sides of the rectangles
    int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;
    // Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    // Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    // If any of the sides from A are outside of B
    if (bottomA <= topB) { return false; }
    if (topA >= bottomB) { return false; }
    if (rightA <= leftB) { return false; }
    if (leftA >= rightB) { return false; }
    // If none of the sides from A are outside B
    return true;
}