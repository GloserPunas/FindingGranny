#include"TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return text;
}
void TextureManager::Draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, text, &src, &dest);
}
