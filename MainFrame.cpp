#include "MainFrame.h"

MainFrame::MainFrame(int delay) : delay(delay) {
    player = new Player(13, 17, "●", Yellow);   // 플레이어 초기화
    map = new Map();     // 맵 초기화
    running = true;

    // 4명의 유령 객체 초기화 (맵의 각 모서리에 배치)
    ghost[0] = new Ghost(2, 2, Red);
    ghost[1] = new Ghost(map_width - 2, 2, Red);
    ghost[2] = new Ghost(2, map_height - 2, Red);
    ghost[3] = new Ghost(map_width - 2, map_height - 2, Red);
}

MainFrame::~MainFrame() {
    delete player;          // 플레이어 객체 메모리 해제
    delete map;             // 맵 객체 메모리 해제
    for (int i = 0; i < 4; i++)
        delete ghost[i];    // 적 객체 메모리 해제
}

void MainFrame::Update() {
    if (player->getScore() == 2350) running = false;        // 점수가 2350에 도달하면 게임 종료
    if (player->isDied()) running = false;                  // 플레이어가 죽으면 게임 종료

    player->Input();
    map->Update();
    player->Update(map);

    for (int i = 0; i < 4; i++) {
        ghost[i]->Update(player, map);
    }

    Sleep(delay);       // 게임 업데이트 주기에 맞춰 대기
}

void MainFrame::Render() {
    map->Render();
    player->Render();
}