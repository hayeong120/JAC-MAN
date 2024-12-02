#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Util.h"
#include "Map.h"
#include "MainFrame.h"

class Game {
private:
    static const int START_Y = 23;

    // 내부 로직 함수
	KeyValue keyControl() const;
	void moveCursor(int& x, int& y, KeyValue key, int minY, int maxY) const;

    void init() const;

public:
    // 게임 인트로 로직
    void showTitle() const;
    int showMenu() const;
    void showInfo() const;
    void loading(int q, int p);

    void run();

};
