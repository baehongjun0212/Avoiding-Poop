#include "Draw.h"

void CDraw::showTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)
{
	// �ؽ�ó ����,���� ������ �ڵ��Է�
	int w,h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	
	// ���
	SDL_Rect dst = {x,y,w,h};
	SDL_RenderCopy(renderer, texture, NULL, &dst);
}