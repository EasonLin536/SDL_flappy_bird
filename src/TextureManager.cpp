#include "TextureManager.h"

SDL_Texture* TextureManager::loadTexture(const char* filename, int& imgWidth, int& imgHeight) {
    SDL_Surface* tempSurface = IMG_Load(filename);
    if (tempSurface == NULL) { cerr << "Unable to load image! SDL_image Error: " << filename << IMG_GetError(); }

    imgWidth = tempSurface->w;
    imgHeight = tempSurface->h;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    if (texture == NULL) { cerr << "Unable to create texture! SDL Error: " << filename << SDL_GetError(); }
    
    SDL_FreeSurface(tempSurface);

    return texture;
}

void TextureManager::free(SDL_Texture* texture) {
    //Free texture if it exists
	if (texture != NULL)	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}