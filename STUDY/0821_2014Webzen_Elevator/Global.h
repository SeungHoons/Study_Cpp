#pragma once
//���̺귯��
#include<iostream>
#include<vector>
#include<deque>						// �������� Ž��												
#include<list>						//deque�� ����Ϸ� ������ �տ��� ���� ���� ���Ϳ� ���� �����ٰ� �ص� �ᱹ �տ��� ��� �ڸ��� ���� �� �޸� �������� �����ؼ� 
#include<set>						//�� �޸� ������ �޸𸮰� ������� �ٽ� �Ҵ��Ұ�
#include<time.h>					//����Ʈ �߿����� �ܹ��� ����Ʈ�� ������ �����Ǿ� 
#include<utility>
#include<map>
using namespace std;

//���� ���


//������
#define MAX_FLOOR 20
#define MAX_PEOPLE 100;


//�̳�
//���� ���������� ����
enum STATE
{
	UP,
	DOWN,
	STOP
};
//���������Ͱ� ��� ��������.
enum ELEVATOR_TYPE
{
	HIGH,
	LOW,
	ALL
};

struct Button
{
	bool upButton = 0;
	bool downButton = 0;
	bool call = 0;
};