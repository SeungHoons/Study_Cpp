#include <iostream>
#include "SingleTone.h"
using namespace std;

int main()
{
	int a = SingleTone::GetInstance()->map[10];
	return 0;
}