#include "Declare.h"
 

int main() {
    SetCursorVisibility(false);

    //##################################################################################
    //##################################################################################
    bool pressed = false;
    int ply = 0;
    int plx = 0;
    char pla = 'o';
    std::ifstream inputFile("STATE.txt");

    if (inputFile.is_open()) {
        inputFile >> plx; 
        inputFile >> ply;
        inputFile >> pla;
        inputFile.close(); 
    }
    else {std::cout << "Unable to open file." << std::endl;}
    //##################################################################################
    //##################################################################################

    
    //##################################################################################
    //##################################################################################
    std::array<std::array<char, mapy>, mapx> game;

    perlin_noise_func(game);
    //for (int y = 0; y < mapy; ++y) {
    //    for (int x = 0; x < mapx; ++x) {
    //        game[x][y] = '#';
    //    }
    //}

    game[plx][ply] = pla;
    render(game, pla);
    //##################################################################################
    //##################################################################################


    //##################################################################################
    //##################################################################################
    while (true) {
        if (GetAsyncKeyState('W') & 0x8000) {
            game[plx][ply] = '#';
            ply = max(ply - 1, 1);
            pressed = true;
        }
        if (GetAsyncKeyState('S') & 0x8000) {
            game[plx][ply] = '#';
            ply = min(ply + 1, mapy - 2); 
            pressed = true;
        }
        if (GetAsyncKeyState('A') & 0x8000) {
            game[plx][ply] = '#';
            plx = max(plx - 1, 1); 
            pressed = true;
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            game[plx][ply] = '#';
            plx = min(plx + 1, mapx - 2);
            //plx = min(plx + 1, mapx - 1);
            pressed = true;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; 
        }
        if (pressed) {
            game[plx][ply] = pla;
            render(game, pla);
            //std::cout << "Press\n";
            footstep();
            pressed = false;
        }
        Sleep(30);
    }
    

    //##################################################################################
    //##################################################################################
    std::ofstream outFile("STATE.txt");
    if (outFile.is_open()) {
        outFile << plx;
        outFile << ply;
        outFile.close();
    }
    else { std::cout << "Unable to open file." << std::endl; }
    //##################################################################################
    //##################################################################################
    SetCursorVisibility(true);
    return 0;
}



