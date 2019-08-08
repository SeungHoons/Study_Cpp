#include <iostream>

using namespace std;


struct Node
{
	int value;
	Node *pNext;
};

int NodeDelete(Node& )
{
	return 0;
}

int main()
{

	//0입력 받을때가지 숫자 입력 받고 그대로 출력

	int input = 0;
	Node *List_ = new Node;
	Node *pCur = List_;
	Node *pStart;
	List_->value = 0;
	List_->pNext = nullptr;

	while (1)
	{

		cin >> input;
		if (input == 0)
			break;



		if (List_->value == 0 && List_->pNext == nullptr)
		{
			List_->value = input;
			pStart = List_;
		}
		else
		{
			List_->pNext = new Node;
			List_->pNext->value = input;
			List_ = List_->pNext;
		}

	}

	pCur = pStart;
	while (true)
	{

		cout << pCur->value << endl;
		if (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		else
		{
			break;
		}
	}

	

	return 0;
}