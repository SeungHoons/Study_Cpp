#include <iostream>
#include <time.h>
using namespace std;

#define QUESTION_NUM 3
int input[QUESTION_NUM];
int Computer[QUESTION_NUM];
int ball_count = 0;
int strike_count = 0;
bool WIN = false;

void Init()
{
	srand((unsigned int)time(nullptr));
	int index = 0;
	while (true)
	{
		if (index > 2)
			break;
		Computer[index] = (rand() % 9) + 1;

		for (int i = 0; i < index; i++)
		{
			if (Computer[index] == Computer[i])
			{
				index--;
				break;
			}
		}
		index++;
	}
}

void Input()
{

	strike_count = 0;
	ball_count = 0;
	for (int i = 0; i < QUESTION_NUM; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < QUESTION_NUM; i++)
	{
		for (int j = 0; j < QUESTION_NUM; j++)
		{
			if (Computer[i] == input[j] && i == j)
			{
				strike_count++;
				break;
			}
			else if (Computer[i] == input[j])
			{
				ball_count++;
				break;
			}
		}
	}
}

void Print()
{
	cout << "\n 볼 : " << ball_count;
	cout << "\n 스트라이크 : " << strike_count;
	cout << "\n\n";
	if (strike_count == 3)
	{
		WIN = true;
		cout << "USER WIN" << endl;
	}
}


int main()
{
	Init();
	//for (int i = 0; i < 3; i++)
	//	cout << Computer[i] << endl;

	while (!WIN)
	{
		Input();
		Print();		
	}
	return 0;
}