#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "Game.h"

class Map
{
public:
    Map();
    ~Map();
    void LoadMap(int arr[20][25]);
    void DrawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* pathwgrass;
    SDL_Texture* ground;
    SDL_Texture* grass;

    int map_[20][25];
};


#endif // MAP_H_INCLUDED
