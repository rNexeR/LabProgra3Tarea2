#include "Menu.h"

Menu::Menu(SDL_Renderer *renderer)
{
    splash.push_back(IMG_LoadTexture(renderer,"menu.png"));
    splash.push_back(IMG_LoadTexture(renderer,"instrucciones.png"));
    SDL_QueryTexture(splash[0], NULL, NULL, &rect.w, &rect.h);
    rect.x = 0;
    rect.y = 0;
}

void Menu::draw(SDL_Renderer* renderer, int pos){
    SDL_RenderCopy(renderer, splash[pos], NULL, &rect);
}

Menu::~Menu()
{
    //dtor
}
