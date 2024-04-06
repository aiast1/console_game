#include "Declare.h"



void SetCursorPosition(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(consoleHandle, position);
}

void render(const std::array<std::array<char, mapy>, mapx>& game, char pla) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int y = 0; y < mapy; ++y) {
        for (int x = 0; x < mapx; ++x) {
            SetCursorPosition(x, y);
            if (game[x][y] == pla) {
                SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << game[x][y];
                SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            switch(game[x][y]){
            case '~':
                SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                std::cout << game[x][y];
                SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            default:
                std::cout << game[x][y];
                break;
            }
        }
    }
    SetCursorPosition(0, mapy);
    //std::cout << "Rendered frame\n";
    std::cout.flush();
}

