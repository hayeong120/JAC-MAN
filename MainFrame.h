#pragma once

#include"Player.h"
#include"Map.h"
#include"Ghost.h"

class MainFrame
{
public:
	MainFrame(int delay);
	~MainFrame();

	bool isRunning() { return running; }
	void Update();
	void Render();

private:
	int	delay;			// ���� ������Ʈ�� ���� �ð�
	bool running;		// ������ ���� ������ ����

	Player* player;
	Map* map;
	Ghost* ghost[4];

};

