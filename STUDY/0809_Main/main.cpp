#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
//c��Ÿ�� ���� ����� fprintf,fscanf
//c++��Ÿ�� ���� ����� 

int main()
{
	ofstream outfile("a.txt", ios::in);
	outfile << "asdfa" << endl;
	outfile.close();
	

	char szBuf[256];
	ifstream inFile("a.txt");
	inFile >> szBuf;
	cout << szBuf;
	inFile.close();

	//getline 
	return 0;
}



//int main()
//{
//	//C
//	FILE* p = fopen("a.txt", "r");
//
//	//���� �ִ� ���� �б�/����
//	//fprintf(p, "%d", 1);		//���°�
//	int a = 0;
//	//fscanf(p, "%d", &a);		//�޾ƿ��°�
//
//
//	//���� ���� ���� �б�/���� ���̳ʸ� ����  
//	char szBuf[256];
//	/*fread(szBuf, sizeof(char), 256, p);
//	printf("%s", szBuf);*/
//	fwrite(szBuf, sizeof(char), 256, p);
//
//	//���Ͽ��� ���ϴ� �κ� ã��
//	fseek(p, 4, SEEK_CUR); /*SEEK_END, SEEK_SET*/
//
//	fclose(p);
//	return 0;
//}



////������ �Ÿ��� ���ϴ� �Լ�
//float getDistance(int x1, int y1, int x2, int y2)
//{
//	return sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1)*(y2 - y1));
//}
//
//struct AAA
//{
//	int a;
//	int b;
//	char szName[256];
//
//};
//
//int main()
//{
//	AAA a;
//	memset(&a, 0, sizeof(a));
//	cout << sqrtf(4) << endl;
//
//	return 0;
//}