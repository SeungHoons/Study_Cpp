#include "SNAKE.h"

SNAKE::SNAKE()
{
	SnakeBodys.resize(1);
}


SNAKE::~SNAKE()
{
}

void SNAKE::Init(MAP* _map)
{
	SnakeBodys[0].x = WIDHT / 2;
	SnakeBodys[0].y = HEIGHT / 2;
	pMap = _map;
}

void SNAKE::Input()
{

}
