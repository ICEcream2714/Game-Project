#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "../include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Window has failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* RenderWindow::loadTexture( const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filepath);

    if (texture == NULL)
        std:: cout << "Failed to load texture. SDL_Error: " << SDL_GetError() << std::endl;
    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}
