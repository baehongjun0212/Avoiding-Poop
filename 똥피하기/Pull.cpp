#include "Pull.h"
#include "stdlib.h"

CPull::CPull(void)
{
	count = 0;
}

void CPull::Create() {
	this->isCollision = false;
	this->x = rand() % 10 * 30;
	int tmp = rand() % 10 * 10;
	this->y = -30 - tmp;
	tmp = rand() % 3;
	if (tmp == 0) this->speed = 4;
	else if (tmp == 1) this->speed = 7;
	else if (tmp == 2) this->speed = 9;

}
void CPull::Process(SDL_Rect char_rect) {
	// 충돌처리 시작
	SDL_Rect pull_rect;
	pull_rect.w = 22;
	pull_rect.h = 20;
	pull_rect.x = this->x + 4;
	pull_rect.y = this->y + 5;
	if (pull_rect.y + pull_rect.h > char_rect.y) {
		if (pull_rect.x > char_rect.x && pull_rect.x < char_rect.x + char_rect.w) {
			isCollision = true;
		}
		else if (pull_rect.x + pull_rect.w > char_rect.x && pull_rect.x + pull_rect.w < char_rect.x + char_rect.w) {
			isCollision = true;
		}
	}

	// 똥 하강 및 완료된똥 리셋
	this->y += this->speed;
	if (this->y >= 400) {
		Create();
		count++;
	}
}

int CPull::getX() {
	return this->x;
}

int CPull::getY() {
	return this->y;
}

int CPull::getCount() {
	return this->count;
}

bool CPull::getCollisionStatus() {
	return this->isCollision;
}