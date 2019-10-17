#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
using namespace std;

int main()
{
	//cout << mysql_get_client_info() << endl;

	MYSQL conn;
	MYSQL_RES* pSqlRes;
	MYSQL_ROW sqlRow;

	if (mysql_init(&conn) == nullptr)
	{
		cout << "mysql_init" << endl;
		return 1;
	}

	if (mysql_real_connect(&conn, "localhost", "hoons", "qwerty", "test_game", 3306, NULL, 0) == nullptr)
	{
		cout << "mysqul_real connect fails!" << endl;
		return 1;
	}

	if (mysql_select_db(&conn, "test_game"))
	{
		cout << "mysql_select_db fail!! : " << mysql_errno(&conn) << " : "<< mysql_error(&conn) << endl;
		return 1;
	}

	const char* query = "SELECT * FROM user_data";

	int state = mysql_query(&conn, query);
	if (state == 0)
	{
		pSqlRes = mysql_store_result(&conn);
		if (pSqlRes != nullptr)//SELECT 문을 뺀 나머지는 null로 반환
		{
			int numCol = mysql_num_fields(pSqlRes);
			while ((sqlRow = mysql_fetch_row(pSqlRes)) != nullptr)
			{
				for (int i = 0; i < numCol; i++)
				{
					cout << sqlRow[i] << " ";
				}
				cout << endl;
			}
			{

			}
		}
		else
		{
			int errNO = mysql_errno(&conn);
			if (errNO != 0)
			{
				cout << "Error : " << mysql_error(&conn) << endl;
			}
		}

		mysql_free_result(pSqlRes);
	}

	mysql_close(&conn);
	return 0;
}