#include "Smtp.h"
#include "API.h"

using namespace std;

int main()
{
	
	CSmtp smtp(
		25,								/*smtp端口*/
		"smtp.163.com",					/*smtp服务器地址*/
		"XXXXXX@163.com",	/*你的邮箱地址*/
		"AWPLAIAJEPAACNCL",					/*邮箱密码*/
		"XXXXX@qq.com",	/*目的邮箱地址*/
		 "文案识别，程序自动发送，请查收！",							/*主题*/
		">>第41页<<有点混乱"		/*邮件正文*/
	);
	
	//添加附件时注意,\一定要写成\\，因为转义字符的缘故
	string filePath("C:\\Users\\ASUS\\Desktop\\NULL.txt");
	smtp.AddAttachment(filePath);
	

	/*还可以调用CSmtp::DeleteAttachment函数删除附件，还有一些函数，自己看头文件吧!*/
	//filePath = "C:\\Users\\李懿虎\\Desktop\\sendEmail.cpp";
	//smtp.AddAttachment(filePath);

	int err;
	if ((err = smtp.SendEmail_Ex()) != 0)
	{
		if (err == 1)
			cout << "错误1: 由于网络不畅通，发送失败!" << endl;
		if (err == 2)
			cout << "错误2: 用户名错误,请核对!" << endl;
		if (err == 3)
			cout << "错误3: 用户密码错误，请核对!" << endl;
		if (err == 4)
			cout << "错误4: 请检查附件目录是否正确，以及文件是否存在!" << endl;
	}
	system("pause");
	return 0;
}