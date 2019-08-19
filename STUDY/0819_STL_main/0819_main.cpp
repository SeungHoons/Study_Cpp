#include <iostream>
#include <algorithm>
#include <string>
using namespace std;



////다시 해보기
//class String
//{
//	char * str;
//public:
//	String(const char* _str) : str(new char[strlen(_str)])
//	{
//		for (int i = 0; i < strlen(_str); i++)
//		{
//			str[i] = _str[i];
//		}
//	}
//	void Print()const
//	{
//		for (int i = 0; i < sizeof(str); i++)
//		{
//			cout << str[i];
//		}
//	}
//};

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void PrintInt(int n) { cout << "테스트 정수 : " << n << endl; }


};


template<typename T>
class ObjectInfo
{
	T data;
public:
	ObjectInfo(const T& d) : data(d) {}
	void Print()
	{
		cout << "타ㅓ입 ; " << typeid(data).name() << endl;
		cout << "크기 : " << sizeof(data) << endl;
		cout << "값 : " << data << endl;
		cout << endl;
	}
};


template<typename T>
class Array
{
	T *buf;
	int size;
	int capacity;
public:
	explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}
	~Array() { delete[] buf; }

	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[](int idx) const
	{
		return buf[idx];
	}

	int GetSize() const
	{
		return size;
	}
};

template<typename IterT, typename Func >
void For_each(IterT begin, IterT end, Func pf)
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

void PrintInt(int data)
{
	cout << data << " ";
}

void PrintString(string data)
{
	cout << data << " ";
}

template<typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
	Pair(const T1& ft, const T2& sd) :first(ft), second(sd){}

};

int main()
{
	Pair<int, int> p1(10, 20);
	cout << p1.first << ',' << p1.second << endl;
	Pair<int, string> p2(1, "one");
	cout << p2.first << ',' << p2.second << endl;
	Pair<int, int> p3(10, 20);
	cout << p3.first << ',' << p3.second << endl;
	Pair<int, string> p4(1, "one");
	cout << p4.first << ',' << p4.second << endl;

	return 0;


}