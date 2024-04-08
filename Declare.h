#pragma once


#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <array>
#include <fstream>
#include <cmath>

const int mapx = 500;//40
const int mapy = 500;//25

//user expirience
void SetCursorVisibility(bool visible);

//map generation
char perlin_noise_func(std::array<std::array<char, mapy>, mapx>& game);

//render
void SetCursorPosition(int x, int y);
void render(const std::array<std::array<char, mapy>, mapx>& game, int plx, int ply, char pla);

//sound
void footstep();
void background_music();

//ui
int start_ui();
