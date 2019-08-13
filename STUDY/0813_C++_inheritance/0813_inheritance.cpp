#include <iostream>
#include <vector>
using namespace std;

class parent
{
protected:
	int a = 0;
public:
	virtual void print()
	{
		cout << a << endl;
	}
	virtual void print2() = 0;
	virtual void printch2() = 0;

};

class child1 : public parent
{
private:
	int c = 10;
public :
	virtual void print()
	{
		cout << c << endl;
	}
	void walk()
	{
		c++;
	}
	virtual void print2()
	{
		cout << c << endl;
	}
	virtual void printch2();

};

class child2 : public parent
{
	virtual void print2()
	{
		cout << a << endl;
	}
	virtual void printch2()
	{
		cout << 12222 << endl;
	}
};

int main()
{
	// parent pt;
	//child2 ch2;
	vector<parent*> vecParent;

	vecParent.push_back(new child1());
	vecParent.push_back(new child2());

	for (auto iter = vecParent.begin(); iter != vecParent.end(); iter++)
	{

		child2* pCh = dynamic_cast<child2*>(*iter);
		if (pCh)
		{
			//pCh->printch2();
		}
		(*iter)->print2();
	}

	

	//vecParent[0]->print();

	//child1 ch1;
	//static_cast<parent>(ch1).print();

	return 0;
}