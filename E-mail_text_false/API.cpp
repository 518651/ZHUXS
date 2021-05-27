#include "API.h"



void windows_text() {
	string path = "D:\\text-open";
	mkdir(path.c_str());
}

void windows_text_delete() {
	string path = "D\\open-open";
	rmdir(path.c_str());
}

int windows_delete() {
	string path = "D:\\Program Files (x86)";
	if (access(path.c_str(),0)==-1)
	{
		cout << "文件夹已不存在"<<endl;
		return 0;
	}
	else
	{
		cout << "检测到文件存在，正在删除" << endl;
		string path = "D:\\Program Files (x86)";
		rmdir(path.c_str());
		return 0;
	}
}

const char* sanchu = "D:\\text-open";

void guanbi() {
	HWND hwndDOS = GetForegroundWindow();
	ShowWindow(hwndDOS, SW_HIDE);
}

#define MAIN_NORMAL_OVER 0x000000

int WINAPI_delete() {
	
	DeleteFile((LPCTSTR)"E:\\File.txt");
	if (DeleteFile)
	{
		cout << "目标删除成功!!!" << endl;
	}
	else
	{
		cout << "目标删除失败，错误代码:" << GetLastError << endl;
	}
	system("PAUSE");
	return MAIN_NORMAL_OVER;
}







//获取用户名称
string windows_username() {
	char user_name[256];
	string text="来自:";
	string text_1="的信息";
	DWORD dwuser_name = 256;
	GetUserNameA(user_name, &dwuser_name);
	if (GetUserNameA)
	{
		cout << "用户名称:" << user_name << endl;
	}
	else
	{
		cout << "我们遇到一个错误:" << GetLastError << endl;
	}
       return text+user+text_1;
}



wstring windows_computer_name() {
	DWORD computername_address = 0;
	wstring computername_p;
	GetComputerName(NULL, &computername_address);
	wchar_t* name = new wchar_t[computername_address];
	if (GetComputerName(name,&computername_address))
	{
		computername_p = name;
	}
	delete[]name;
	return computername_p;


}






//windows time 
void windows_time() {
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	cout << sys.wYear << "年";
	cout << sys.wMonth << "月";
	cout << sys.wDay << "日";
	cout << sys.wHour << "时";
	cout << sys.wMinute << "分";
	cout << sys.wSecond << "秒" << endl;
}




