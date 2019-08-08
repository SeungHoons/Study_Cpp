#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
using namespace std;


#define FPS 30.0f
#define HEIGHT 25
#define WIDTH 15
#define ENEMYNUMS 10

bool ING = true;



int maps[HEIGHT][WIDTH];

enum eMap
{
	EMPTY,
	BLOCK,
	ENEMY,
	ITEM,
	USER
};

struct sCharacter
{
	int x;
	int y;
	int score;
};

void Input(sCharacter& user)
{
	if (_kbhit())
	{
		char input = getch();
		int tem_x = 0;

		switch (input)
		{
		case 'a':
			if (maps[user.y][user.x - 1] != BLOCK)
			{
				tem_x = user.x;
				if (maps[user.y][user.x - 1] == ITEM)
					user.score += 100;
				user.x--;
				maps[user.y][tem_x] = EMPTY;
			}
			break;
		case 'd':
			if (maps[user.y][user.x + 1] != BLOCK)
			{
				tem_x = user.x;
				if (maps[user.y][user.x + 1] == ITEM)
					user.score += 100;
				user.x++;
				maps[user.y][tem_x] = EMPTY;
			}
			break;
		default:
			break;
		}

		maps[user.y][user.x] = USER;

	}
}

void Init(sCharacter enemy[], sCharacter& user)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == WIDTH - 1)
			{
				maps[i][j] = 1;
			}
			else
			{
				maps[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < ENEMYNUMS; i++)
	{
		enemy[i].x = 1 + rand() % (WIDTH - 2);
		enemy[i].y = (rand() % HEIGHT) - HEIGHT;
	}
	user.x = WIDTH / 2;
	user.y = HEIGHT - 1;
	user.score = 0;

}


void Update(sCharacter enemy[] , sCharacter& user)
{
	int temp = 0;
	for (int i = 0; i < ENEMYNUMS; i++)
	{
		temp = enemy[i].y;
		enemy[i].y++;
		if (enemy[i].y >= 0)
		{
			maps[enemy[i].y][enemy[i].x] = ENEMY;
			maps[temp][enemy[i].x] = EMPTY;
		}
		if (enemy[i].y > HEIGHT)
		{
			enemy[i].y = 0;
			enemy[i].x = 1 + rand() % (WIDTH -2);
			user.score += 100;
		}
		if (user.x == enemy[i].x && user.y == enemy[i].y)
		{
			ING = false;

		}
	}
	
}

void Draw()
{
	system("cls");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			switch (maps[i][j])
			{
			case EMPTY:
				cout << "  ";
				break;
			case BLOCK:
				cout << "¢Â";
				break;
			case ENEMY:
				cout << "¡â";
				break;
			case USER:
				cout << "¡ã";
				break;
			default:
				break;
			}
		}
		cout << "\n";
	}

}

void Release()
{
	cout << "======= G A M E = O V E R ======" << endl;
}


int main()
{
	srand(time(nullptr));

	sCharacter user_1;
	sCharacter enemy[ENEMYNUMS];

	Init(enemy, user_1);
	while (ING)
	{
		Input(user_1);
		Update(enemy, user_1);
		Draw();
		cout << "\n\n =====  S C O R E : " << user_1.score;
		Sleep(1000 / FPS);
	}

	Release();



	int num = rand() & 100;
	return 0;
}