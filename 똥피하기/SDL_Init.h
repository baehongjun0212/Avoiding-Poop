#pragma once

#include "SDL.h"
#include "SDL_Image.h"

class CSDL_Init
{
public:
	CSDL_Init(void);
	~CSDL_Init(void);
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	void Loop();
private:
	bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;

	// 게임 텍스쳐
	SDL_Texture* character; // 32x48
	SDL_Texture* ddong; // 30x30
};
