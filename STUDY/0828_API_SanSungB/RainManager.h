#pragma once
#include"Global.h"
class Rain;
class RainManager
{
private:
	vector<string*>  Word;
	string loadStirng;
	int wordCount;
public:
	RainManager();
	~RainManager();

	void loadWord();
	void createWord();
};

