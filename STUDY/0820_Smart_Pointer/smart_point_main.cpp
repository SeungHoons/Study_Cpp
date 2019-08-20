#include <iostream>
#include <vector>
#include <memory>
#include "TestClass.h"
using namespace std;

int main()
{
	//shared_ptr<TestClass> sptr1(new TestClass);
	shared_ptr<TestClass> sptr1 = make_shared<TestClass>();
	shared_ptr<TestClass> sptr2 = sptr1;
	cout << sptr1.use_count() << endl;		//카운터 2;

	//순환 참조 할때 사용 //참조만 하고 해제는 알아서 해라 느낌.
	TestClass* pTest = sptr1.get();
	weak_ptr<TestClass> wptr1 = sptr1;
	wptr1.lock();

	//전형적인 관리 바법
	vector<shared_ptr<TestClass>> vec;
	vec.push_back(make_shared<TestClass>());		//make_shared 또는 new

	//옛날 방법
	auto_ptr<TestClass>();
	//복사 불가 (복사가 일어나면 안될때) 복사가 하고싶으면 move()함수 호출
	unique_ptr<TestClass> uptr(new TestClass());
	unique_ptr<TestClass> uptr2 = move(uptr);


	cout << sptr1.use_count() << endl;

	return 0;
}