#pragma once
class SingleTone
{
private :
	static SingleTone* pThis;

	
public:
	int map[20];
	SingleTone();
	~SingleTone();
	static SingleTone* GetInstance()
	{
		if (pThis == nullptr)
			pThis = new SingleTone();
		return pThis;
	}

	static void Release()
	{
		if(pThis != nullptr)
			delete pThis;
	}
};

