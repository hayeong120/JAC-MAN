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
	int	delay;			// 게임 업데이트의 지연 시간
	bool running;		// 게임이 실행 중인지 여부

	Player* player;
	Map* map;
	Ghost* ghost[4];

};

