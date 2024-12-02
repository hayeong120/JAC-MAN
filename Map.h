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
	void Update();		// 맵의 상태를 업데이트하는 함수
	void Render();		// 맵을 렌더링하는 함수
	int GetItem(int x, int y);

private:
	char	map[map_height][map_width];				// 맵의 실제 데이터를 저장하는 배열
	char	back_buffer[map_height][map_width];		// 화면 버퍼 (이전 상태)
	char	front_buffer[map_height][map_width];	// 화면 버퍼 (현재 상태)
	vector<Point>	point;
	vector<Item>	item;

public:
	inline void setMapInfo(int x, int y, char state) { map[y][x] = state; }
	inline char getMapInfo(int x, int y) { return map[y][x]; }
	inline void setBuffer(int x, int y, char state) { back_buffer[y][x] = state; }
};
