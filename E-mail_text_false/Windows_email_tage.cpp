#include "API.h"
//#include "Smtp.h"

void Windows_email_tou_name() {
	char user_name[256];
	DWORD dwuser_name = 256;
	GetUserNameA(user_name, &dwuser_name);
	/*if (GetUserNameA)
	{
		cout << "�û�����:" << user_name << endl;
	}
	else
	{
		cout << "��������һ������:" << GetLastError << endl;
	}*/


	char message[1000];
	memset(message, 0, 200);
	char Windows_address[] = "����������:%s";
	sprintf_s(message, Windows_address, user_name);
	cout << message << endl;
}