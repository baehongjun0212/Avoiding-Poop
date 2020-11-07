#pragma once

#include "SDL.h"

class CPull
{

public:
	CPull(void);
	void Create();
	void Process(SDL_Rect);
	int getX();
	int getY();
	int getCount();
	bool getCollisionStatus();
private:
	int x,y;
	int speed; // 떨어지는 속도
	int count; // 다 떨어진 똥 개수카운트
	bool isCollision;
};