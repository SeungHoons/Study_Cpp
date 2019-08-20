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
	cout << sptr1.use_count() << endl;		//ī���� 2;

	//��ȯ ���� �Ҷ� ��� //������ �ϰ� ������ �˾Ƽ� �ض� ����.
	TestClass* pTest = sptr1.get();
	weak_ptr<TestClass> wptr1 = sptr1;
	wptr1.lock();

	//�������� ���� �ٹ�
	vector<shared_ptr<TestClass>> vec;
	vec.push_back(make_shared<TestClass>());		//make_shared �Ǵ� new

	//���� ���
	auto_ptr<TestClass>();
	//���� �Ұ� (���簡 �Ͼ�� �ȵɶ�) ���簡 �ϰ������ move()�Լ� ȣ��
	unique_ptr<TestClass> uptr(new TestClass());
	unique_ptr<TestClass> uptr2 = move(uptr);


	cout << sptr1.use_count() << endl;

	return 0;
}