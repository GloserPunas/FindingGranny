#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include"Game.h"

class GameObject
{
public:
    GameObject (const char* textureSheet, int x, int y, int height_, int width_);
    ~GameObject();
    void UpdateObj();
    void Render();
    int xpos, ypos, height, width;
private:
    //int xpos, ypos, height, width;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;

};

#endif // GAMEOBJECT_H_INCLUDED
