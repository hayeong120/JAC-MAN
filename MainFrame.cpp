#include "MainFrame.h"

MainFrame::MainFrame(int delay) : delay(delay) {
    player = new Player(13, 17, "��", Yellow);   // �÷��̾� �ʱ�ȭ
    map = new Map();     // �� �ʱ�ȭ
    running = true;

    // 4���� ���� ��ü �ʱ�ȭ (���� �� �𼭸��� ��ġ)
    ghost[0] = new Ghost(2, 2, Red);
    ghost[1] = new Ghost(map_width - 2, 2, Red);
    ghost[2] = new Ghost(2, map_height - 2, Red);
    ghost[3] = new Ghost(map_width - 2, map_height - 2, Red);
}

MainFrame::~MainFrame() {
    delete player;          // �÷��̾� ��ü �޸� ����
    delete map;             // �� ��ü �޸� ����
    for (int i = 0; i < 4; i++)
        delete ghost[i];    // �� ��ü �޸� ����
}

void MainFrame::Update() {
    if (player->getScore() == 2350) running = false;        // ������ 2350�� �����ϸ� ���� ����
    if (player->isDied()) running = false;                  // �÷��̾ ������ ���� ����

    player->Input();
    map->Update();
    player->Update(map);

    for (int i = 0; i < 4; i++) {
        ghost[i]->Update(player, map);
    }

    Sleep(delay);       // ���� ������Ʈ �ֱ⿡ ���� ���
}

void MainFrame::Render() {
    map->Render();
    player->Render();
}