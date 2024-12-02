#pragma once
#include "Util.h"
#include"Map.h"

class Player
{
public:
	Player(int x, int y, const char* img, COLOR color);
	~Player();

public:
	void Input();				// 사용자 입력을 받는 함수
	void Update(Map* map);		// 플레이어 상태를 업데이트하는 함수
	void Render();				// 플레이어를 렌더링하는 함수

	void getItem();				// 아이템을 얻을 때 호출되는 함수

private:
	int x, y;				// 플레이어의 위치
	char img[3];			// 플레이어 이미지 (문자형태로 저장)
	Direction state;  			// 플레이어의 상태 (이동 방향 등)
	int score;				// 플레이어의 점수
	COLOR color;			// 플레이어의 색상

	bool Buff;			// 플레이어가 버프 상태 여부
	int BuffStart;		// 버프 시작 시간

	bool isDie;			// 플레이어가 죽었는지 여부


public:
	// getter와 setter 함수들
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setImg(const char* img) { strcpy_s(this->img, img); }
	void setIsDie(bool temp) { this->isDie = temp; }

	int getX() { return x; }
	int getY() { return y; }
	const char* getImg() { return img; }
	int getState() { return state; }
	int getScore() { return score; }
	bool isDied() { return isDie; }
	bool isBuff() { return Buff; }
};
