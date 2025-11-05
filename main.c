#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>


int tworzenieLini(SDL_Renderer* renderWFunkcji, int pX,int pY,int kX,int kY)
{
    // if (pY > kY) {
    //     int meowMeowUwU = pY;
    //
    //     pY = kY;
    //     kY = meowMeowUwU;
    // }
    // if (pX > kX) {
    //     int meowMeowUwU = pX;
    //
    //     pX = kX;
    //     kX = meowMeowUwU;
    // }

    int deltaX = kY - pY;
    int deltaY = kX - pX;

    

    double pierwiastek = sqrt( deltaX*deltaX + deltaY*deltaY);


    double proporcjeX = (double)pierwiastek / deltaX;
    double proporcjeY = (double)pierwiastek / deltaY;

    proporcjeX = (double)deltaY / (double)deltaX;
    proporcjeY = (double)deltaX / (double)deltaY;

    double licznikX = 0;
    double licznikY = 0;

    for (int i = 0; i < pierwiastek; i++) {
        for (int superProporcjeX = 0; superProporcjeX < proporcjeX; superProporcjeX++) {
            SDL_RenderDrawPoint(renderWFunkcji, pY + (int)licznikX + superProporcjeX, pX + (int)licznikY);
        }
        for (int superProporcjeY = 0; superProporcjeY < proporcjeY; superProporcjeY++) {
            SDL_RenderDrawPoint(renderWFunkcji, pY + (int)licznikX , pX + (int)licznikY + superProporcjeY);
        }
        licznikX = (double)licznikX + (double)proporcjeX;
        licznikY = (double)licznikY + (double)proporcjeY;

        if (licznikX >= kY || licznikY >= kX) {break;}
    }
}


int poczatekX = 10;
int poczatekY = 10;

int wysokoscY = 50;
int szerokoscX = 50;

int katX = 16;
int katY = 10;

int main() {
    SDL_Window* meowOkno = SDL_CreateWindow (
        "FajneOkno",
        150,
        100,
        1500,
        1000,
        SDL_WINDOW_SHOWN
        );

    SDL_Renderer* meowRender = SDL_CreateRenderer (meowOkno, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event meowEvent;
    SDL_RenderSetLogicalSize(meowRender,150,100);

    int wyloczanieProgramu = 1;

    while (wyloczanieProgramu) {
        SDL_SetRenderDrawColor(meowRender,0,0,0,255);
        SDL_RenderClear(meowRender);
        SDL_SetRenderDrawColor(meowRender,255,255,255,255);


        int tablica[2][2] =
        {
            {0,0},
            {katX,katY}
        };
        for (int i = 0; i < 2; i++) {

            SDL_RenderDrawLine(meowRender,poczatekX + tablica[i][0], poczatekY+ tablica[i][1], poczatekX+ tablica[i][0], poczatekY + wysokoscY+ tablica[i][1]);
            SDL_RenderDrawLine(meowRender,poczatekX+szerokoscX+ tablica[i][0], poczatekY+ tablica[i][1], poczatekX+szerokoscX+ tablica[i][0], poczatekY + wysokoscY+ tablica[i][1]);
            SDL_RenderDrawLine(meowRender,poczatekX+ tablica[i][0], poczatekY+ tablica[i][1], poczatekX+szerokoscX+ tablica[i][0], poczatekY+ tablica[i][1]);
            SDL_RenderDrawLine(meowRender,poczatekX+ tablica[i][0], poczatekY+wysokoscY+ tablica[i][1], poczatekX+szerokoscX+ tablica[i][0], poczatekY+wysokoscY+ tablica[i][1]);
        }
        SDL_RenderDrawLine(meowRender,poczatekX,poczatekY,poczatekX+katX,poczatekY+katY);
        SDL_RenderDrawLine(meowRender,poczatekX+szerokoscX,poczatekY,poczatekX+katX+szerokoscX,poczatekY+katY);

        SDL_RenderDrawLine(meowRender,poczatekX,poczatekY+wysokoscY,poczatekX+katX,poczatekY+katY+wysokoscY);
        SDL_RenderDrawLine(meowRender,poczatekX+szerokoscX,poczatekY+wysokoscY,poczatekX+katX+szerokoscX,poczatekY+katY+wysokoscY);


        while (SDL_PollEvent(&meowEvent)) {
            if (meowEvent.type == SDL_QUIT ) {
                wyloczanieProgramu = 0;
            }
            if (meowEvent.type == SDL_KEYDOWN) {
                if (meowEvent.key.keysym.sym == SDLK_a) {
                    katX--;
                }
                else if (meowEvent.key.keysym.sym == SDLK_d) {
                    katX++;
                }
                else if (meowEvent.key.keysym.sym == SDLK_s) {
                    katY--;
                }
                else if (meowEvent.key.keysym.sym == SDLK_w) {
                    katY++;
                }
                else if (meowEvent.key.keysym.sym == SDLK_LEFT) {
                    szerokoscX--;
                }
                else if (meowEvent.key.keysym.sym == SDLK_RIGHT) {
                    szerokoscX++;
                }
                else if (meowEvent.key.keysym.sym == SDLK_UP) {
                    wysokoscY--;
                }
                else if (meowEvent.key.keysym.sym == SDLK_DOWN) {
                    wysokoscY++;
                }
            }
        }

        SDL_RenderPresent(meowRender);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer (meowRender);
    SDL_DestroyWindow (meowOkno);
    return 0;


}