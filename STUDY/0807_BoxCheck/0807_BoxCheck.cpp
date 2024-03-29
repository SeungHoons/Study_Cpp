// 0807_BoxCheck.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define WIDTH 19
#define HEIGHT 19


enum e_map
{
	EMPTY,
	BLOCK,
	ITEM,
	USER

};

struct s_character
{
	int x;
	int y;
	int score;
};


int maps[HEIGHT][WIDTH] =
{
	{	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{	1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,2,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,2,0,0,0,1,0,0,0,1,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,1},
	{	1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


int init(s_character& user)
{
	user.x = 2;
	user.y = 2;
	maps[user.y][user.x] = USER;

	return 0;
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
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "▣";
				break;
			case 2:
				cout << "♥";
				break;
			case 3:
				cout << "△";
				break;
			default:
				break;
			}
		}

		cout << endl;
	}
}
int Move(s_character& user)
{
	char input;
	input = _getch();
	int tem_x = 0;
	int tem_y = 0;

	
	switch (input)
	{
	case 'w':
		if (maps[user.y - 1][user.x] != BLOCK)
		{
			tem_y = user.y;
			if (maps[user.y - 1][user.x] == ITEM)
				user.score += 100;
			user.y--;
			maps[tem_y][user.x] = EMPTY;
		}
		break;
	case 's':
		if (maps[user.y + 1][user.x] != BLOCK)
		{
			tem_y = user.y;
			if (maps[user.y + 1][user.x] == ITEM)
				user.score += 100;
			user.y++;
			maps[tem_y][user.x] = EMPTY;
		}
		break;
	case 'a':
		if (maps[user.y][user.x-1] != BLOCK)
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

	return 0;
}




int main()
{
	s_character user_1 = { 0,0,0 };
	init(user_1);
	

	while (true)
	{
		Draw();
		cout << "\n\n==========스코어 : " << user_1.score;
		Move(user_1);
	}
}

