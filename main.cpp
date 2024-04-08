#include "Declare.h"
#include <thread> 


const double PI = 3.14159265;


enum ArrowDirection {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

ArrowDirection calculateArrowDirection(int mouseX, int mouseY, int arrowX, int arrowY);



int main() {

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int arrowX = screenWidth / 2; 
    int arrowY = screenHeight / 2;

    POINT cursorPos;
    ArrowDirection direction_buff = RIGHT;
    //################console fullscreen and renamed#######################################
    
    SetCursorVisibility(false);
    SetConsoleTitle(TEXT("simple game"));//rename window

    

    //#############################load state###########################################
    //##################################################################################
    bool pressed = false;
    int ply = 0;
    int plx = 0;
    char pla = '>';
    std::ifstream inputFile("STATE.txt");

    if (inputFile.is_open()) {
        inputFile >> plx; 
        inputFile >> ply;
        inputFile.close(); 
    }
    else {std::cout << "Unable to open file." << std::endl;}
    //##################################################################################
    
    

    //####################################ui############################################
    //##################################################################################
    start_ui();
    std::cout << "ui";
    //##################################################################################
    

    //####pointing#############
    int xlook = 1;
    int ylook = 0;


    //###############################create map#########################################
    //##################################################################################
    std::array<std::array<char, mapy>, mapx> game;

    perlin_noise_func(game);

    char pastchar = game[plx][ply];
    game[plx][ply] = pla;
    render(game, plx, ply, pla);      
    //##################################################################################
    



    //###################################game loop######################################
    //##################################################################################
    while (true) {

        #pragma warning(disable : 28020)
        char up    =   game[plx][ply - 1];
        char down  =   game[plx][ply + 1];
        char left  =   game[plx - 1][ply];
        char right =   game[plx + 1][ply];
        #pragma warning(default : 28020)

        


        if ((GetAsyncKeyState('W') & 0x8000) && (up != '^')) {
            game[plx][ply] = pastchar;
            ply = max(ply - 1, 1);
            pressed = true;
        }
        if ((GetAsyncKeyState('S') & 0x8000) && (down != '^')) {
            game[plx][ply] = pastchar;
            ply = min(ply + 1, mapy - 2); 
            pressed = true;
        }
        if ((GetAsyncKeyState('A') & 0x8000) && (left != '^')) {
            game[plx][ply] = pastchar;
            plx = max(plx - 1, 1); 
            pressed = true;
        }
        if ((GetAsyncKeyState('D') & 0x8000) && (right != '^')) {
            game[plx][ply] = pastchar;
            plx = min(plx + 1, mapx - 2);
            pressed = true;
        }
        //###


        
        GetCursorPos(&cursorPos);

        ArrowDirection direction = calculateArrowDirection(cursorPos.x, cursorPos.y, arrowX, arrowY);
        if (direction_buff != direction) {
            switch (direction) {
            case UP:
                xlook = 0;
                ylook = -1;
                pla = '^';
                break;
            case DOWN:
                xlook = 0;
                ylook = 1;
                pla = 'v';
                break;
            case LEFT:
                xlook = -1;
                ylook = 0;
                pla = '<';
                break;
            case RIGHT:
                xlook = 1;
                ylook = 0;
                pla = '>';
                break;
            }
            pressed = true;
        }
        direction_buff = direction;

        //###
        if (GetAsyncKeyState('E') & 0x8000) {
            game[plx + xlook][ply + ylook] = '#';
            pressed = true;
        }
        //########
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            exit(0);
            break; 
        }
        if (pressed) {
            game[plx][ply] = pla;
            render(game, plx, ply, pla);
            footstep();
            pressed = false;
        }
        Sleep(30);
    }
    

    //###############################save###############################################
    //##################################################################################
    std::ofstream outFile("STATE.txt");
    if (outFile.is_open()) {
        outFile << plx << std::endl;
        outFile << ply << std::endl;
        outFile.close();
    }
    else { std::cout << "Unable to open file." << std::endl; }
    //##################################################################################
    //##################################################################################
    SetCursorVisibility(true);
    
    return 0;
}


ArrowDirection calculateArrowDirection(int mouseX, int mouseY, int arrowX, int arrowY) {
    double angle = atan2(mouseY - arrowY, mouseX - arrowX) * 180 / PI;

    if (angle >= -45 && angle < 45)
        return RIGHT;
    else if (angle >= 45 && angle < 135)
        return DOWN;
    else if (angle >= -135 && angle < -45)
        return UP;
    else
        return LEFT;
}
