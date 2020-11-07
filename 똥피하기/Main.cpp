#include <stdio.h>
#include "SDL.h"
#include "SDL_Init.h"

int main(int argc, char **argv)
{
	CSDL_Init game;
	game.Loop();
	SDL_Quit();
	return 0;
}

// clean
