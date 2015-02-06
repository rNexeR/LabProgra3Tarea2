#ifndef MENU_H
#define MENU_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
using namespace std;

class Menu
{
    public:
        vector<SDL_Texture*> splash;
        Menu(SDL_Renderer *renderer);

        SDL_Rect rect;
        void draw(SDL_Renderer* renderer, int pos);
        virtual ~Menu();
    protected:
    private:
};

#endif // MENU_H
