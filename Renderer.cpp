#include "Declare.h"

#include <algorithm> 
#undef max
#undef min
 

const int VIEWPORT_WIDTH = 30;
const int VIEWPORT_HEIGHT = 18;

void SetCursorPosition(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(consoleHandle, position);
}

void render(const std::array<std::array<char, mapy>, mapx>& game, int plx, int ply, char pla) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);


    int halfViewportWidth = VIEWPORT_WIDTH / 2;
    int halfViewportHeight = VIEWPORT_HEIGHT / 2;

    int viewportStartX = plx - halfViewportWidth;
    viewportStartX = std::max(0, viewportStartX); 
    viewportStartX = std::min(viewportStartX, mapx - VIEWPORT_WIDTH); 

    int viewportStartY = ply - halfViewportHeight;
    viewportStartY = std::max(0, viewportStartY); 
    viewportStartY = std::min(viewportStartY, mapy - VIEWPORT_HEIGHT); 



    for (int y = 0; y < VIEWPORT_HEIGHT; ++y) {
        for (int x = 0; x < VIEWPORT_WIDTH; ++x) {
            int mapX = viewportStartX + x;
            int mapY = viewportStartY + y;

            SetCursorPosition(x, y);

            
            if (mapX == plx && mapY == ply) {
                SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << pla;
            }
            else {
                
                char terrain = game[mapX][mapY];
                switch (terrain) {
                case '~':
                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                    break;
                case '.':
                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    break;
                default:
                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                }
                std::cout << terrain;
            }
        }
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    SetCursorPosition(0, VIEWPORT_HEIGHT);
}



