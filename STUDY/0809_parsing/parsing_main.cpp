#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


struct Homework
{
	int index; //¿Œµ¶Ω∫
};


int main()
{
	FILE* ps = fopen("Homework.csv", "r");
	string variable_name;
	string data_type;
	string comment;

	int count_num = 0;


	char tempChar;
	while ( (tempChar=fgetc(ps))!='\n')
	{
		if (tempChar == ',')
			count_num++;
		variable_name += tempChar;
	}

	while ((tempChar = fgetc(ps)) != '\n')
	{
		data_type += tempChar;
	}
	while ((tempChar = fgetc(ps)) != '\n')
	{
		comment += tempChar;
	}


	FILE* outPs = fopen("Homework.h", "w");
	fprintf(outPs, "struct Homework\n{\n");

	int i_name=0;
	int i_datatype=0;
	int i_coment=0;

	for (int i = 0; i <= count_num; i++)
	{

		fprintf(outPs, "\t");
		while (data_type[i_datatype] != ',')
		{
			fprintf(outPs, "%c", data_type[i_datatype++]);
		}

		fprintf(outPs, " ");
		while (variable_name[i_name] != ',')
		{
			fprintf(outPs, "%c", variable_name[i_name++]);
		}

		fprintf(outPs, ";//");

		while (comment[i_coment] != ',')
		{
			fprintf(outPs, "%c", comment[i_coment++]);
		}
		fprintf(outPs, "\n");

		i_name++;
		i_datatype++;
		i_coment++;
	}
	fprintf(outPs, "\n}");
	fclose(outPs);
	fclose(ps);
	return 0;
}