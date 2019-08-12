#include "MAP.h"
#include "SNAKE.h"
#include <time.h>

#define FPS 30.0f

int main()
{
	MAP map;
	SNAKE snake;
	srand((unsigned int)time(nullptr));


	map.Init();
	snake.Init(&map);
	map.DrawMap();

	while (true)
	{
		snake.Input();
		snake.Move();
		map.DrawMap();
		_sleep(1000 / FPS);
	}
	return 0;
}