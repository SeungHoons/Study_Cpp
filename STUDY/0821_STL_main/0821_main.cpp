#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
using namespace std;




int main()
{
	map<int, int > m;



	m[5] = 100;
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;


	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "(" << (*iter).first << ',' << (*iter).second << ")" << " ";
	}
	cout << endl;

	m[5] = 200;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	}
	cout << endl;


	return 0;
}