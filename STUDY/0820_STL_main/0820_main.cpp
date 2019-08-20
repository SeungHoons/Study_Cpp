#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;

//람다식
//[캡쳐](파라미터) -> 리턴 타입 {함수}

bool Less(int &l, int &r)
{
	return l < r;
}

int main()
{

	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	vector<int>::iterator iter2;

	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	iter = v.begin() + 2;

	iter2 = v.erase(iter);
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	iter2 = v.erase(v.begin()+1, v.end());

	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	return 0;
}