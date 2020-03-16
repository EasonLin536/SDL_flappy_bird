#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


using namespace std;

class Game {
public:
	Game();
	~Game();
	// Initialize the game	
	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
    // Use while loop to keep pulling events
	void handleEvents();
	// Update every object
	void update();
	// Render every object
	void render();

	void restart();

	void clean();

	bool running() { return isRunning; }
	
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	//Box collision detector
	static bool checkCollision(SDL_Rect, SDL_Rect);

	enum StateEnum {
		GAME_HOME = 0,
		GAME_TUTORIAL = 1,	
		GAME_OVER = 2,
		GAME_QUIT = 3,
		GAME_START = 4,
		GAME_RESTART = 5
	};
	static StateEnum state_enum;
	static int state;

private:
	bool isRunning;
	SDL_Window* window;
};

#endif