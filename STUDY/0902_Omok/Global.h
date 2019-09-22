#pragma once

// window h
#include <Windows.h>
#include <vector>
#include <chrono>

using namespace std;


//my header
#include "macro.h"
#include "PACKET_HEADER.h"

//define
#define FPS 60.0f
#define MAP_TILE_WIDHT_HEIGHT 13
#define TILE_SIZE 40
#define TILE_START_POINT_X 50
#define TILE_START_POINT_Y 25
#define BULLET_NUM 3

//enum
enum DIRECTION
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

struct F_POSITION
{
	float x;
	float y;
};

