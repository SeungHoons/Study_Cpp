#pragma once
//���̺귯��
#include<iostream>
#include<vector>
#include<deque> // �������� Ž��	
//deque�� ����Ϸ� ������ �տ��� ���� ���� ���Ϳ� ���� �����ٰ� �ص� �ᱹ �տ��� ��� �ڸ��� ���� �� �޸� �������� �����ؼ� 
//�� �޸� ������ �޸𸮰� ������� �ٽ� �Ҵ��Ұ�
//����Ʈ �߿����� �ܹ��� ����Ʈ�� ������ �����Ǿ� 
#include<list>
#include<set>
#include<time.h>
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