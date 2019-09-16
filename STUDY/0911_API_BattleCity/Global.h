#pragma once

// window h
#include <Windows.h>
#include <vector>
#include <chrono>

using namespace std;


//my header
#include "macro.h"

//define
#define MAP_TILE_WIDHT_HEIGHT 13
#define TILE_SIZE 40
#define TILE_START_POINT_X 50
#define TILE_START_POINT_Y 25

//enum
enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

