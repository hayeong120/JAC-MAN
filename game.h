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

    // ���� ���� �Լ�
	KeyValue keyControl() const;
	void moveCursor(int& x, int& y, KeyValue key, int minY, int maxY) const;

    void init() const;

public:
    // ���� ��Ʈ�� ����
    void showTitle() const;
    int showMenu() const;
    void showInfo() const;
    void loading(int q, int p);

    void run();

};
