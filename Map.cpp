#include "Map.h"

Map::Map()
{
	char temp[map_height][map_width + 1] = {
		"###########################" ,
		"#............#............#" ,
		"#.####.#####.#.#####.####.#" ,
		"#*####.#####.#.#####.####*#" ,
		"#.####.#####.#.#####.####.#" ,
		"#.........................#" ,
		"#.####.##.#######.##.####.#" ,
		"#.####.##.#######.##.####.#" ,
		"#......##....#....##......#" ,
		"######.##### # #####.######" ,
		"     #.##### # #####.#     " ,
		"     #.##         ##.#     " ,
		"     #.## ##   ## ##.#     " ,
		"######.## #     # ##.######" ,
		"      .             .      " ,
		"######.## #     # ##.######" ,
		"     #.## ##   ## ##.#     " ,
		"     #.##         ##.#     " ,
		"     #.##.#######.##.#     " ,
		"######.##....#....##.######" ,
		"#......#####.#.#####......#" ,
		"#.####.#####.#.#####.####.#" ,
		"#.####.#####.#.#####.####.#" ,
		"#*..##...............##..*#" ,
		"###.##.##.#######.##.##.###" ,
		"###.##.##....#....##.##.###" ,
		"#......#####.#.#####......#" ,
		"#.##########.#.##########.#" ,
		"#.........................#" ,
		"###########################" ,
	};

	__POS _temp;

	// �� �����͸� �ʱ�ȭ
	for (int i = 0; i < map_height; i++) {
		for (int j = 0; j < map_width; j++) {
			switch (temp[i][j]) {
			case ' ': map[i][j] = SPACE; break;
			case '#': map[i][j] = WALL;  break;
			case '.': _temp.x = j; _temp.y = i; point.push_back(_temp); map[i][j] = SPACE; break;
			case '*': _temp.x = j; _temp.y = i; item.push_back(_temp);  map[i][j] = SPACE; break;
			}
			back_buffer[i][j] = map[i][j];	// �ʱ�ȭ �� �� ���ۿ� �� ������ ����
		}
	}

}


Map::~Map() {}

void Map::Update()
{
	// point ���Ϳ� �ִ� ����Ʈ �������� ��ġ�� back_buffer�� ������Ʈ
	for (vector<Point>::iterator iter = point.begin();
		iter != point.end(); iter++)
		back_buffer[iter->y][iter->x] = _POINT;

	// item ���Ϳ� �ִ� �������� ��ġ�� back_buffer�� ������Ʈ
	for (vector<Item>::iterator iter = item.begin();
		iter != item.end(); iter++)
		back_buffer[iter->y][iter->x] = ITEM;
}

void Map::Render()
{
	// ȭ�鿡 ����� �κи� ���
	for (int i = 0; i < map_height; i++) {
		for (int j = 0; j < map_width; j++) {
			if (back_buffer[i][j] != front_buffer[i][j]) {
				gotoxy(j * 2, i);
				switch (back_buffer[i][j]) {
				case _POINT:	setColor(LightYellow); std::cout << ". "; break;
				case ITEM:  setColor(LightYellow); std::cout << "��"; break;
				case SPACE: setColor(White); std::cout << "  "; break;
				case WALL:  setColor(Blue);  std::cout << "��"; break;
				case PLAYER:setColor(LightYellow); std::cout << "��"; break;
				case ENEMY:setColor(Red);	std::cout << "��"; break;
				case DIED_ENEMY:setColor(Blue); std::cout << "��";
				}
			}
			front_buffer[i][j] = back_buffer[i][j];		// ȭ�� ���� ����
			back_buffer[i][j] = map[i][j];				// �� ���� ����
		}
	}
}

int Map::GetItem(int x, int y)
{
	for (vector<Point>::iterator iter = point.begin(); iter != point.end(); iter++) {
		if (x == iter->x && y == iter->y)
		{
			point.erase(iter);	// ����Ʈ ������ ����
			return _POINT;
		}
	}
	for (vector<Item>::iterator iter = item.begin(); iter != item.end(); iter++) {
		if (x == iter->x && y == iter->y)
		{
			item.erase(iter);	// ���� ������ ����
			return ITEM;
		}
	}
	return SPACE;
}