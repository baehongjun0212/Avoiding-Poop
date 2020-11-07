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
	int speed; // �������� �ӵ�
	int count; // �� ������ �� ����ī��Ʈ
	bool isCollision;
};