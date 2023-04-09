#include"Game.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"TextureManager.h"
#include"GameObject.h"
#include "Map.h"

using namespace std;

SDL_Renderer*Game::renderer = nullptr;

SDL_Event Game::event;


SDL_Surface* surface = IMG_Load("Image/welcome_screen.png");

GameObject* character;
GameObject* cat;
GameObject* cat2;
GameObject* flower;
GameObject* tree;
GameObject* house;


Map* map_;

int posx = 500, posy = 350;
SDL_Texture* playerText;
SDL_Rect srcR, destR;
Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char* title, int x, int y, int height, int width, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)== 0)
    {
        cout << "Subsystem initialized" << endl;
        window = SDL_CreateWindow(title, x, y, height,  width, flags);
        if(window)
        {
            cout << "Window created" << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 250, 200, 200, 0);
            cout << "Renderer created" << endl;
        }
        isRunning = true;
    }
    else isRunning = false;

    character = new GameObject("Image/maincharacter1.png", 200, 200, 64, 32);
    cat = new GameObject("Image/MeoMyDieu1.png", 350, 350, 64, 60);
    cat2 = new GameObject("Image/cat2.png", 350, 500, 32, 64);
    flower = new GameObject("Image/flower.png", 200, 64, 29, 29);
    house = new GameObject("Image/blue_house2.png", 1, 10, 300, 255);

    map_ = new Map();
}
void Game::update()
{
    //character -> UpdateObj();
    //cat -> UpdateObj();
    cat2 -> UpdateObj();
    flower -> UpdateObj();
    house -> UpdateObj();


}
void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            cat2 ->xpos += 5;
            break;
        case SDLK_LEFT:
            cat2->xpos -= 5;
            break;
        case SDLK_UP:
            cat2->ypos -= 5;
            break;
        case SDLK_DOWN:
            cat2->ypos += 5;
            break;
        default:
            break;
        }
    }
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    //add function here
    SDL_Texture* screen = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, screen, NULL, NULL);


//*//
    map_ ->DrawMap();
    //character -> Render();
    //cat -> Render();
    flower -> Render();
    house -> Render();
    cat2 -> Render();
//*//
    SDL_RenderPresent(renderer);
}
bool Game::running(){
return isRunning;}
