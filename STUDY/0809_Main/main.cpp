#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
//c스타일 파일 입출력 fprintf,fscanf
//c++스타일 파일 입출력 

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
//	//서식 있는 파일 읽기/쓰기
//	//fprintf(p, "%d", 1);		//적는거
//	int a = 0;
//	//fscanf(p, "%d", &a);		//받아오는거
//
//
//	//서식 없는 파일 읽기/쓰기 바이너리 저장  
//	char szBuf[256];
//	/*fread(szBuf, sizeof(char), 256, p);
//	printf("%s", szBuf);*/
//	fwrite(szBuf, sizeof(char), 256, p);
//
//	//파일에서 원하는 부분 찾기
//	fseek(p, 4, SEEK_CUR); /*SEEK_END, SEEK_SET*/
//
//	fclose(p);
//	return 0;
//}



////두점의 거리를 구하는 함수
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