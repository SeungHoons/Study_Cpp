#pragma once
#include "Global.h"
class KeyManager
{
private:
	KeyManager();
	static KeyManager* pThis;

public:
	~KeyManager();

	static KeyManager* GetInstance()
	{
		if (pThis == nullptr)
			pThis = new KeyManager();
		return pThis;
	}

	static void Release()
	{
		if (pThis != nullptr)
			delete pThis;
	}

	void input(WPARAM wParam);
};

