#include "RainManager.h"
#include "Rain.h"
#include<iostream>

RainManager::RainManager()
{
	wordCount = 0;
}


RainManager::~RainManager()
{
}

void RainManager::loadWord()
{
	FILE* ps;
	ps = fopen("word.txt", "r");
	char sz;

	while ((sz = fgetc(ps)) != EOF)
	{
		if (sz == ',')
			wordCount++;
		loadStirng += sz;
	}
	//if (ps != nullptr)
	//{
	//	getline(cin, loadStirng, '\0');
	//}
}

void RainManager::createWord()
{
	int index=0;
	int index2 = 0;
	string *tempString;
	char c;
	for (int i = 0; i < wordCount; i++)
	{
		tempString = new string();
		for (index; index < loadStirng.size(); index++)
		{
			if (loadStirng[index] == *",")
			{
				break;
			}
			c = loadStirng[index];
			*tempString = *tempString + c;
		}
		Word.push_back(tempString);
		index+=2;
	}
}


