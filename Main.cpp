#include "SDL.h"
#include <stdio.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;                    // Declare a pointer
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

int main(int argc, char* argv[]) {
    if(!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if(!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);

            SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
        }
        
    }
    
    // getchar();
    close();
    return 0;
}

bool init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error:%s\n", SDL_GetError());
         success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow(
            "SDL Toturial",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
        );
        
        if(gWindow == NULL)
        {
            printf("Window coundnot be created! SDL_Error:%s\n", SDL_GetError());
             success = false;
        }
        else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
                
            SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format,
                0xCC, 0xCC, 0xCC));
            SDL_UpdateWindowSurface(gWindow);

            // SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
            
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    gHelloWorld = SDL_LoadBMP("./hello_world.bmp");
    if(gHelloWorld == NULL)
    {
        printf("SDL could not load image! SDL_Error:%s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void close()
{
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Clean up
    SDL_Quit();
}
