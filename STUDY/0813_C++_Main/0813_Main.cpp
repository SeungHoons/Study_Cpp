#include<iostream>
#include<assert.h>
#include<vector>
#include<map>
#include<string>

#define __FILE__
#define __LINE__

using namespace std;


//»ó¼Ó


//class POINT
//{
//public:
//	int x; 
//	int y;
//	POINT operator+(POINT& right)
//	{
//		x += right.x;
//		y += right.y;
//		return *this;
//	}
//};
//
//int main()
//{
//	POINT a, b;
//	a + b;
//}

//int main()
//{
//	map<int, string> mMap;
//	pair<int, string>p;
//	p.first = 1;
//	p.second = "³ª¶ù¸»½Î¹Ì";
//	//mMap.insert(p);
//
//	mMap.insert(make_pair(1, "³ª¶ù¸»½Î¹Ì"));
//}


//template <typename T, typename T2>
//T sum(T a, T2 b)
//{
//	return a + b;
//}
//
//int main()
//{
//
//	vector<int> iVec;
//
//	iVec.reserve(10);
//
//	iVec.push_back(2);
//	iVec.push_back(35);
//	iVec.push_back(32);
//	
//
//	for (vector<int>::iterator iter = iVec.begin(); iter != iVec.end(); iter++)
//	{
//		*iter;//ÀÌ°Ô °ª iter´Â ÁÖ¼Ò
//	}
//
//	for (auto iter = iVec.begin(); iter != iVec.end(); iter++)
//	{
//
//	}
//
//	for (auto now : iVec)
//	{
//
//	}
//
//
//	for (int i = 0; iVec.size(); i++)
//		cout << iVec[i] << endl;
//
//	int a = 0;
//	cout << sum(a, 3.32);
//	//assert(a != 0);
//	return 0;
//}