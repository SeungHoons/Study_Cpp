// 0807_strstr_LetItgo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>


using namespace std;

int main()
{

	char song[1024 * 10] = { "The snow glows white on the mountain tonight\
								Not a footprint to be seen\
								A kingdom of isolation\
								And it looks like I'm the queen\
								The wind is howling like this swirling storm inside\
								Couldn't keep it in, heaven knows I've tried\
								Don't let them in, don't let them see\
								Be the good girl you always have to be\
								Conceal, don't feel, don't let them know\
								Well, now they know\
								Let it go, let it go\
								Can't hold it back anymore\
								Let it go, let it go\
								Turn away and slam the door\
								I don't care what they're going to say\
								Let the storm rage on\
								The cold never bothered me anyway\
								Let it go, let it go\
								Can't hold it back anymore\
								Let it go, let it go\
								Turn away and slam the door\
								Let it go(go, go, go go, go go, go go, go, go, go go)\
								Let it go\
								Let it go\
								Let it go\
								It's funny how some distance makes everything seem small\
								And the fears that once controlled me can't get to me at all\
								It's time to see what I can do\
								To test the limits and break through\
								No right, no wrong, no rules for me\
								I'm free\
								Let it go, let it go\
								I am one with the wind and sky\
								Let it go, let it go\
								You'll never see me cry\
								Here I stand and here I stay\
								Let the storm rage on\
								My power flurries through the air into the ground\
								My soul is spiraling in frozen fractals all around\
								And one thought crystallizes like an icy blast\
								I'm never going back, the past is in the past\
								Let it go\
								The cold never bothered me anyway\
								Let it go, let it go\
								And I'll rise like the break of dawn\
								Let it go, let it go\
								That perfect girl is gone\
								Here I stand in the light of day\
								Let the storm rage on"
	};

	int count = 0;
	bool one = false;
	char tempStr[1024 * 10];
	strcpy(tempStr, song);

	while (true)
	{
		if (strstr(tempStr, "Let it go") != NULL)
		{
			strcpy(tempStr, strstr(tempStr, "Let it go") + 5);
			count++;
			cout << count << endl;
		}
		else
			break;
	}
	strcpy(tempStr, song);

	while (true)
	{
		if (strstr(tempStr, "let it go") != NULL)
		{
			strcpy(tempStr, strstr(tempStr, "let it go") + 5);
			count++;
			cout << count << endl;
		}
		else
			break;
	}



}
