#include <iostream>

using namespace std;

int Fac(int num)
{
	if (num <= 1)
		return 1;

	return num * Fac(num - 1);
}



int main()
{
	cout<<Fac(5);
	return 0;
}

//int main()
//{
//	//���� �Ѱ� �Է��� �ް� 
//	// ex) 5
//	//5���� ���� ������ �Ҵ��ϰ� 
//	//5�� �Է� �ް� ���
//	//
//	
//
//	int input;
//	int* nums;
//
//	cin >> input;
//
//	nums = new int[input];
//	for (int i = 0; i < input; i++)
//	{
//		cin >> nums[i];
//	}
//	cout << endl;
//	for (int i = 0; i < input; i++)
//	{
//		cout << nums[i] <<endl;
//	}
//
//	
//	delete[] nums;
//
//	return 0;
//}