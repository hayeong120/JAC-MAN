#pragma once
#include "Util.h"
#include"Map.h"

class Player
{
public:
	Player(int x, int y, const char* img, COLOR color);
	~Player();

public:
	void Input();				// ����� �Է��� �޴� �Լ�
	void Update(Map* map);		// �÷��̾� ���¸� ������Ʈ�ϴ� �Լ�
	void Render();				// �÷��̾ �������ϴ� �Լ�

	void getItem();				// �������� ���� �� ȣ��Ǵ� �Լ�

private:
	int x, y;				// �÷��̾��� ��ġ
	char img[3];			// �÷��̾� �̹��� (�������·� ����)
	Direction state;  			// �÷��̾��� ���� (�̵� ���� ��)
	int score;				// �÷��̾��� ����
	COLOR color;			// �÷��̾��� ����

	bool Buff;			// �÷��̾ ���� ���� ����
	int BuffStart;		// ���� ���� �ð�

	bool isDie;			// �÷��̾ �׾����� ����


public:
	// getter�� setter �Լ���
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
