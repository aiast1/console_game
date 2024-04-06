#include "Declare.h"



void SetCursorVisibility(bool visible) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.dwSize = 10;
    cursorInfo.bVisible = visible;

    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}