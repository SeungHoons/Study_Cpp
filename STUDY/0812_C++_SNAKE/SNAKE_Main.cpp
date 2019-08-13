#include "MAP.h"
#include "SNAKE.h"
#include <time.h>

#define FPS 30.0f

int main()
{
	MAP map;
	SNAKE snake;


	map.Init();
	snake.Init(&map);
	map.DrawMap();

	while (true)
	{
		snake.Input();
		if (snake.Move())
			break;

		map.DrawMap();
		cout<< "======Score : " << snake.getScore() << "\n";
		//_sleep(1000 / FPS);
	}

	cout << "\n ======Game Over";

	getch();
	return 0;
}