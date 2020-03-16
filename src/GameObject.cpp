#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) : xPos(x), yPos(y) {
    objTexture = TextureManager::loadTexture(texturesheet, width, height);
}

