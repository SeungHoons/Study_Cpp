#include "SNAKE.h"

SNAKE::SNAKE()
{
	Snake.resize(1);
}


SNAKE::~SNAKE()
{

}

void SNAKE::Init(MAP* _map)
{
	Snake.front().x = WIDTH / 2;
	Snake.front().y = HEIGHT / 2;
	pMap = _map;
	pMap->SetPlayer(Snake.front().x, Snake.front().y);
}

void SNAKE::Input()
{

	if (_kbhit())
	{
		char input;
		input = _getch();
		switch (input)
		{
		case 'w':
			if (State != DOWN)
				State = UP;
			break;
		case 's':
			if (State != UP)
				State = DOWN;
			break;
		case 'a':
			if (State != RIGHT)
				State = LEFT;
			break;
		case 'd':
			if (State != LEFT)
				State = RIGHT;
			break;
		default:
			break;
		}
	}
}

void SNAKE::Move()
{
	BODY temp;
	temp = Snake.back();
	for (int i = Snake.size() - 1; i > 0; i--)
	{
		Snake[i] = Snake[i - 1];
	}
	switch (State)
	{
	case RIGHT:
		if (pMap->isWhatObject(Snake.front().x + 1, Snake.front().y) == EMPTY
			|| pMap->isWhatObject(Snake.front().x + 1, Snake.front().y) == ITEM)
		{
			if (pMap->isWhatObject(Snake.front().x + 1, Snake.front().y) == ITEM)
			{
				Snake.push_back(Snake.back());
			}
			Snake.front().x++;
		}
		break;
	case LEFT:
		if (pMap->isWhatObject(Snake.front().x - 1, Snake.front().y) == EMPTY
			|| pMap->isWhatObject(Snake.front().x - 1, Snake.front().y) == ITEM)
		{
			if (pMap->isWhatObject(Snake.front().x - 1, Snake.front().y) == ITEM)
			{
				Snake.push_back(Snake.back());
			}
			Snake.front().x--;
		}
		break;

	case DOWN:
		if (pMap->isWhatObject(Snake.front().x, Snake.front().y + 1) == EMPTY
			|| pMap->isWhatObject(Snake.front().x, Snake.front().y + 1) == ITEM)
		{
			if (pMap->isWhatObject(Snake.front().x , Snake.front().y + 1) == ITEM)
			{
				Snake.push_back(Snake.back());
			}
			Snake.front().y++;
		}
		break;

	case UP:
		if (pMap->isWhatObject(Snake.front().x, Snake.front().y - 1) == EMPTY
			|| pMap->isWhatObject(Snake.front().x, Snake.front().y - 1) == ITEM)
		{
			if (pMap->isWhatObject(Snake.front().x, Snake.front().y-1 ) == ITEM)
			{
				Snake.push_back(Snake.back());
			}
			Snake.front().y--;
		}
		break;

	default:
		break;
	}
	

	for (int i = 0; i < Snake.size(); i++)
	{
		pMap->SetPlayer(Snake[i].x, Snake[i].y);
	}
	
	pMap->SetEmpty(temp.x, temp.y);
	

}
