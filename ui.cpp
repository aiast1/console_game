#include "Declare.h"

using namespace std;

enum OPTIONS { START_GAME, CONTROLS, QUIT_GAME };



void SetCursorPosition_ui(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(consoleHandle, position);
}


void displayMenu(int highlight) {
    system("cls"); 

    for (int i = START_GAME; i <= QUIT_GAME; i++) {
        SetCursorPosition_ui(10, 5 + i * 2); // Adjust positioning 
        if (i == highlight) {
            cout << "<";
        }

        if (i == START_GAME) {
            cout << "Start Game";
        }
        else if (i == CONTROLS) {
            cout << "Controls";
        }
        else if (i == QUIT_GAME) {
            cout << "Quit Game";
        }

        if (i == highlight) {
            cout << ">";
        }
    }
}

int start_ui() {
    int selectedItem = START_GAME;
    displayMenu(selectedItem);

    while (true) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            selectedItem--;
            if (selectedItem < START_GAME) {
                selectedItem = QUIT_GAME;
            }
            displayMenu(selectedItem);
            
            Sleep(150);
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            selectedItem++;
            if (selectedItem > QUIT_GAME) {
                selectedItem = START_GAME;
            }
            displayMenu(selectedItem);
            
            Sleep(150);
        }

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            
            if (selectedItem == START_GAME) {
                //
                system("cls");
                break;
            }

            else if (selectedItem == CONTROLS) {
                system("cls");
                cout << "simple game";
                std::cin.get();
                break;
            }

            else if (selectedItem == QUIT_GAME) {
                system("cls");
                exit(0);
                break;
            }
            Sleep(150); // Delay preventing multiple selections
        }
    }

    return 0;
}
