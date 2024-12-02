#pragma once
#include"Util.h"

const int map_width = 27;
const int map_height = 30;

class Map
{
public:
	Map();
	~Map();

public:
	void Update();		// ���� ���¸� ������Ʈ�ϴ� �Լ�
	void Render();		// ���� �������ϴ� �Լ�
	int GetItem(int x, int y);

private:
	char	map[map_height][map_width];				// ���� ���� �����͸� �����ϴ� �迭
	char	back_buffer[map_height][map_width];		// ȭ�� ���� (���� ����)
	char	front_buffer[map_height][map_width];	// ȭ�� ���� (���� ����)
	vector<Point>	point;
	vector<Item>	item;

public:
	inline void setMapInfo(int x, int y, char state) { map[y][x] = state; }
	inline char getMapInfo(int x, int y) { return map[y][x]; }
	inline void setBuffer(int x, int y, char state) { back_buffer[y][x] = state; }
};
