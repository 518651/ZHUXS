#include "API.h"
//#include "Smtp.h"

void Windows_email_tou_name() {
	char user_name[256];
	DWORD dwuser_name = 256;
	GetUserNameA(user_name, &dwuser_name);
	/*if (GetUserNameA)
	{
		cout << "用户名称:" << user_name << endl;
	}
	else
	{
		cout << "我们遇到一个错误:" << GetLastError << endl;
	}*/


	char message[1000];
	memset(message, 0, 200);
	char Windows_address[] = "发送者名称:%s";
	sprintf_s(message, Windows_address, user_name);
	cout << message << endl;
}