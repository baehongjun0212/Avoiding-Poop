#include "Draw.h"

void CDraw::showTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)
{
	// 텍스처 가로,세로 사이즈 자동입력
	int w,h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	
	// 출력
	SDL_Rect dst = {x,y,w,h};
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}