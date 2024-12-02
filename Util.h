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

const int STOP = 0;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int WALL = 5;
const int SPACE = 6;
const int _POINT = 7;
const int ITEM = 8;
const int PLAYER = 9;
const int ENEMY = 10;
const int DIED_ENEMY = 11;

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

