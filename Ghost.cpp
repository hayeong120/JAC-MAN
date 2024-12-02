#include "Ghost.h"

// 가까운 방향
bool compare1(DnL a, DnL b) {
	return a.length < b.length;
}

// 먼 방향
bool compare2(DnL a, DnL b) {
	return a.length > b.length;
}

// 생성자
Ghost::Ghost(int x, int y, COLOR color) :
	x(x), y(y), color(color)
{
	isDie = false;
	state = STOP;
}

// 소멸자
Ghost::~Ghost() { }

inline long Ghost::getLength(int posx, int posy, int targetx, int targety)
{
	long a = (float)(posx - targetx);
	long b = (float)(posy - targety);
	float result = sqrt(((a * a) + (b * b)));
	return (long)(result * 100000);		// 거리 계산 후 정수로 반환
}

// 뱡향 결정
void Ghost::selectDir(int x, int y, bool asc)
{
	DnL		dnl[4];
	dnl[0].dir = UP;
	dnl[0].length = getLength(this->x, this->y - 1, x, y);
	dnl[1].dir = DOWN;
	dnl[1].length = getLength(this->x, this->y + 1, x, y);
	dnl[2].dir = LEFT;
	dnl[2].length = getLength(this->x - 1, this->y, x, y);
	dnl[3].dir = RIGHT;
	dnl[3].length = getLength(this->x + 1, this->y, x, y);

	if (asc == true)
		sort(dnl, dnl + 4, compare1);		// 가까운 방향을 우선순위로 정렬
	else
		sort(dnl, dnl + 4, compare2);		// 먼 방향을 우선순위로 정렬

	for (int i = 0; i < 4; i++)
		proDir[i] = dnl[i].dir;			// 방향 선택
}

void Ghost::Update(Player* player, Map* map)
{
	if (isDie == true)
		selectDir(map_width / 2, map_height / 2, true);		// 죽었으면 중앙으로 향함
	else if (player->isBuff())
		selectDir(player->getX(), player->getY(), false);	// 플레이어가 버프 상태일 때는 멀리 가도록
	else
		selectDir(player->getX(), player->getY(), true);	// 플레이어 추격

	bool flag = false;
	for (int i = 0; i < 4 && flag == false; i++) {
		switch (proDir[i]) {
		case UP:
			y -= 0.6f, flag = true;
			if (map->getMapInfo(x, y) == WALL || map->getMapInfo(x, y) == ENEMY) y += 0.6f, flag = false;
			break;
		case DOWN:
			y += 0.6f, flag = true;
			if (map->getMapInfo(x, y) == WALL || map->getMapInfo(x, y) == ENEMY) y -= 0.6f, flag = false;
			break;
		case LEFT:
			x -= 0.6f, flag = true;
			if (x < 0) x = map_width - -1, flag = true;
			if (map->getMapInfo(x, y) == WALL || map->getMapInfo(x, y) == ENEMY) x += 0.6f, flag = false;;
			break;
		case RIGHT:
			x += 0.6f, flag = true;;
			if (x == map_width) x = 0, flag = true;
			if (map->getMapInfo(x, y) == WALL || map->getMapInfo(x, y) == ENEMY) x -= 0.6f, flag = false;
			break;
		}
	}

	if (player->getX() == (int)x && player->getY() == (int)y) {
		if (player->isBuff() == true)
			isDie = true;		// 플레이어가 버프 상태일 때 적을 죽임
		else
			player->setIsDie(true);		// 플레이어가 적과 충돌하면 플레이어가 죽음
	}

	if (isDie && x == map_width / 2 && y == map_height / 2)
		isDie = false;		// 적이 죽었을 때 중앙에 도달하면 부활

	map->setBuffer((int)x, (int)y, !isDie ? ENEMY : DIED_ENEMY);		// 맵에 적 위치 업데이트

}
