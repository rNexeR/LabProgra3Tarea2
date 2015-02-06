
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>
#include "Sho.h"
#include "Pause.h"
#include "Menu.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background;
SDL_Rect rect_background;


int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1024/*WIDTH*/, 768/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    Sho sho(renderer);
    Pause pausa(renderer);
    Menu menu(renderer);
    char state = 'M';

//    //Main Loop
    int frame=0;
//    int animacion_sho = 0;
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }

            if(Event.type == SDL_KEYDOWN)
            {
                if(state!='R' && Event.key.keysym.sym == SDLK_p)
                    state = state=='R'? 'P' : 'R';
                if(state=='M' && Event.key.keysym.sym == SDLK_i)
                    state = 'I';
                if(state=='M' && Event.key.keysym.sym == SDLK_j)
                    state = 'R';
                if(state=='M' && Event.key.keysym.sym == SDLK_ESCAPE)
                    return 0;
            }
        }



        SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);

        // Clear the entire screen to our selected color.
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        if (state == 'M'){
            menu.draw(renderer, 0);
        }else if(state=='I'){
            menu.draw(renderer, 1);
        }if (state == 'R'){
            sho.draw(renderer);
            sho.act();
        }else if(state == 'P'){
            pausa.draw(renderer);
        }

        SDL_RenderPresent(renderer);


        frame++;
    }

	return 0;
}




