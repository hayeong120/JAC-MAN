#pragma once
#include"Util.h"
#include"Player.h"
#include"Map.h"  

class Ghost
{
private:
	float x;
	float y;
	COLOR color;
	STATE state;
	STATE proDir[4];
	bool isDie;

public:
	Ghost(int x, int y, COLOR color);
	~Ghost();

	inline long getLength(int posx, int posy, int targetx, int targety);
	void selectDir(int posx, int posy, bool asc);
	void Update(Player* player, Map* map);

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void setColor(COLOR newColor) { this->color = newColor; }
	COLOR getColor() { return color; }
};

