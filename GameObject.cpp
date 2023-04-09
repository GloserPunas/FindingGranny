#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int height_, int width_ )
{
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
    height = height_;
    width = width_;
}
void GameObject::UpdateObj()
{
    //xpos++;
    //ypos--;
    destRect.h = height;
    destRect.w = width;
    destRect.x = xpos;
    destRect.y = ypos;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL , &destRect);
}
