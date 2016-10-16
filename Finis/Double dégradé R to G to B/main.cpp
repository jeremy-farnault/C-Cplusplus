#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main ( int argc, char** argv )
{
    int i,j=255;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran = NULL, *colonnePixel[512] = {NULL};
    SDL_Rect position;
    ecran = SDL_SetVideoMode(512, 512, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Dégradé b&n", NULL);
    for (i=0;i<=512;i++)
        colonnePixel[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,512,1,32,0,0,0,0);
    for (i=0;i<=255;i++)
    {
        SDL_FillRect(colonnePixel[i], NULL, SDL_MapRGB(ecran->format, j, i, 0));
        position.x = 0;
        position.y = i;
        SDL_BlitSurface(colonnePixel[i], NULL, ecran, &position);
        j--;
    }
    j = 255;
    for (i=256;i<=511;i++)
    {
        SDL_FillRect(colonnePixel[i], NULL, SDL_MapRGB(ecran->format, 0, j, i));
        position.x = 0;
        position.y = i;
        SDL_BlitSurface(colonnePixel[i], NULL, ecran, &position);
        j--;
    }
    SDL_Flip(ecran);
    pause();
    for (i=0;i<=255;i++)
    {
        SDL_FreeSurface(colonnePixel[i]);
    }
    SDL_Quit();

    return EXIT_SUCCESS;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
