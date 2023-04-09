#include <iostream>
#include <SDL.h>
#include<SDL_image.h>
#include<math.h>

using namespace std;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;
const SDL_Color CYAN = {0, 255, 255};
const SDL_Color WHITE = {255 , 255 , 255};
const SDL_Color PINK = {250,200, 200};
void logSDLError(std::ostream& os,
    const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
    SDL_Quit();
    exit(1);
    }
}
const string WINDOW_TITLE = "HomeLate";
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
    SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
    if ( SDL_WaitEvent(&e) != 0 &&
    (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
    return;
    SDL_Delay(100);
    }
}
