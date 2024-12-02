#pragma once
#include <cmath>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef char STATE;
typedef char COLOR;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightYellow = 14,
    BrightWhite = 15
};

// 키보드 값
enum class KeyValue { UP, DOWN, LEFT, RIGHT, SUBMIT, NONE };

// 플레이어 방향 열거형
enum Direction { STOP, UP, DOWN, LEFT, RIGHT };

enum TileType {
    WALL = 5,
    SPACE = 6,
    _POINT = 7,
    ITEM = 8,
    PLAYER = 9,
    ENEMY = 10,
    DIED_ENEMY = 11
};

typedef struct __POS {
    int x;
    int y;
} Point, Item;

typedef struct __DIRnLENGTH {
    STATE dir;
    long length;
} DnL;

void hideCursor();				// 콘솔 커서를 숨김
void gotoxy(int x, int y);		// 콘솔 커서를 특정 위치로 이동
void setColor(ConsoleColor color);	// 콘솔 텍스트 색상 설정

