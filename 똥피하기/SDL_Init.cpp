#include "SDL_Init.h"
#include "Draw.h"
#include "Pull.h"
#include <stdio.h>
#include <windows.h>

CSDL_Init::CSDL_Init(void)
{
	quit = false;

	// 비디오 생성 오류일시 종료
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) quit = true;

	// 창 생성 및 오류일시 종료
	window = SDL_CreateWindow("Watch Out! Hong Jun!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 300, 400, SDL_WINDOW_SHOWN);
	if (window == NULL) quit = true;

	// 렌더러 생성 및 오류일시 종료
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) quit = true;

	// SDL image 초기화 추가
	IMG_Init(IMG_InitFlags::IMG_INIT_PNG);

	// 게임데이터 로딩 (캐릭터)
	SDL_Surface* tmp = IMG_Load("hongjun.png");
	if (tmp == NULL) quit = true;
	SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 109, 109));
	character = SDL_CreateTextureFromSurface(renderer, tmp);

	// 게임데이터 로딩 (똥)
	tmp = IMG_Load("ddong.png");
	if (tmp == NULL) quit = true;
	SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 255, 255));
	ddong = SDL_CreateTextureFromSurface(renderer, tmp);
}

CSDL_Init::~CSDL_Init(void)
{
	SDL_DestroyTexture(character);
	SDL_DestroyTexture(ddong);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Renderer* CSDL_Init::getRenderer(void)
{
	return renderer;
}

SDL_Window* CSDL_Init::getWindow(void)
{
	return window;
}

void CSDL_Init::Loop() {
	srand(GetTickCount());

	int x = 0; // 캐릭터 좌표
	SDL_Rect rect_char;
	rect_char.w = 21;
	rect_char.h = 48;
	rect_char.x = x + 6;
	rect_char.y = 352;
	bool left = false, right = false; // 이동검사

	CPull pull[10];
	for (int i = 0; i < 10; i++) {
		pull[i].Create();
	}

	// 루프 시작
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_LEFT:
					left = true;
					break;
				case SDLK_RIGHT:
					right = true;
					break;
				}
			}
			else if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
				case SDLK_LEFT:
					left = false;
					break;
				case SDLK_RIGHT:
					right = false;
					break;
				}
			}
		}
		if (left) {
			if (x != 0) x -= 5;
		}
		else if (right) {
			if (x != 270) x += 5;
		}
		rect_char.x = x + 6;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		// 내용시작

		CDraw::showTexture(character, renderer, x, 352);
		for (int i = 0; i < 10; i++) {
			pull[i].Process(rect_char);
			CDraw::showTexture(ddong, renderer, pull[i].getX(), pull[i].getY());
			if (pull[i].getCollisionStatus()) {
				int count = 0;
				for (int i = 0; i < 10; i++) count += pull[i].getCount();
				char msg[100];
				sprintf_s(msg, "YOU LOSE!! (count: %d)", count);
				MessageBox(NULL, msg, "HEY!!", MB_OK);
				quit = true;
			}
		}

		// 종료

		SDL_RenderPresent(renderer);
		SDL_Delay(20);
	}
}