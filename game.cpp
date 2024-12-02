#include "game.h"

// Ű �Է� ó��
KeyValue Game::keyControl() const {
    int key = _getch();

    if (key == 0 || key == 224) { // Ư�� Ű Ȯ��
        key = _getch();
        switch (key) {
        case 72: return KeyValue::UP;
        case 75: return KeyValue::LEFT;
        case 77: return KeyValue::RIGHT;
        case 80: return KeyValue::DOWN;
        }
    }
    else { // �Ϲ� Ű
        switch (key) {  // �����̽��� �Ǵ� ���͹�
        case 32: case 13: return KeyValue::SUBMIT;
        }
    }
    return KeyValue::NONE;
}

// Ŀ�� �̵� ó��
void Game::moveCursor(int& x, int& y, KeyValue key, int minY, int maxY) const {
    if (key == KeyValue::UP && y > minY) {
        gotoxy(x - 2, y--);
        std::cout << " ";
        gotoxy(x - 2, y);
        std::cout << ">";
    }
    if (key == KeyValue::DOWN && y < maxY) {
        gotoxy(x - 2, y++);
        std::cout << " ";
        gotoxy(x - 2, y);
        std::cout << ">";
    }
}

// �ܼ� �ʱ�ȭ
void Game::init() const {
    system("mode con cols = 50 lines = 50 | title Jac-Man");
}

// Ÿ��Ʋ ���
void Game::showTitle() const {
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t  #####   #    ####       #   #   #   #   # \n";
    std::cout << "\t    #    # #  #           ## ##  # #  ##  # \n";
    std::cout << "\t    #   ##### #     ##### # # # ##### # # # \n";
    std::cout << "\t  # #   #   # #           #   # #   # #  ## \n";
    std::cout << "\t   #    #   #  ####       #   # #   # #   # \n";
}

// ���� ���� ���
void Game::showInfo() const {
    system("cls");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t          [���۹�]\n\n";
    std::cout << "\t\t     �̵� : ����Ű �̿�\n";
    std::cout << "\t\t���� : �����̽��� �Ǵ� ����\n\n\n";
    std::cout << "\t\t      ������ : ���Ͽ�\n";
    while (true) {
        if (keyControl() == KeyValue::SUBMIT) {
            break;
        }
    }
}

// �޴� ��� �� �Է�
int Game::showMenu() const {
    int x = 25, y = START_Y;

    // �޴� ǥ��
    gotoxy(x - 2, y);
    std::cout << ">";
    gotoxy(x, START_Y);
    std::cout << " �� �� �� ��";
    gotoxy(x, START_Y + 1);
    std::cout << " �� �� �� ��";
    gotoxy(x, START_Y + 2);
    std::cout << " ��       ��";

    while (true) {
        KeyValue key = keyControl();
        moveCursor(x, y, key, START_Y, START_Y + 2);
        if (key == KeyValue::SUBMIT) {
            return y - START_Y;
        }
    }

}

// �ε� ȭ��
void Game::loading(int q, int p) {
    int x = 19, y = 15;
    system("cls");
    gotoxy(x, y);
    for (int i = 0; i <= q; i++)
        std::cout << "��";
    for (int i = 0; i <= p; i++)
        std::cout << "��";
    gotoxy(x, y + 2);
    std::cout << "\t   loading...";
    Sleep(100);
    system("cls");
}

// ���� ����
void Game::run() {
    while (true) {
        showTitle();
        int menuCode = showMenu();
        if (menuCode == 0) {    // ���� ����
            for (int i = 0; i < 10; i++)
                loading(i, 10 - i);

            MainFrame* mainFrame = new MainFrame(100);

            while (mainFrame->isRunning()) {
                mainFrame->Update();
                mainFrame->Render();
            }
        }
        else if (menuCode == 1) {   // ���� ����
            showInfo();
        }
        else if (menuCode == 2) {   // ����
            return;
        }
        system("cls");
    }
}