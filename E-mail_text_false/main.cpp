#include "Smtp.h"
#include "API.h"

using namespace std;

int main()
{
	
	CSmtp smtp(
		25,								/*smtp�˿�*/
		"smtp.163.com",					/*smtp��������ַ*/
		"XXXXXX@163.com",	/*��������ַ*/
		"AWPLAIAJEPAACNCL",					/*��������*/
		"XXXXX@qq.com",	/*Ŀ�������ַ*/
		 "�İ�ʶ�𣬳����Զ����ͣ�����գ�",							/*����*/
		">>��41ҳ<<�е����"		/*�ʼ�����*/
	);
	
	//��Ӹ���ʱע��,\һ��Ҫд��\\����Ϊת���ַ���Ե��
	string filePath("C:\\Users\\ASUS\\Desktop\\NULL.txt");
	smtp.AddAttachment(filePath);
	

	/*�����Ե���CSmtp::DeleteAttachment����ɾ������������һЩ�������Լ���ͷ�ļ���!*/
	//filePath = "C:\\Users\\��ܲ��\\Desktop\\sendEmail.cpp";
	//smtp.AddAttachment(filePath);

	int err;
	if ((err = smtp.SendEmail_Ex()) != 0)
	{
		if (err == 1)
			cout << "����1: �������粻��ͨ������ʧ��!" << endl;
		if (err == 2)
			cout << "����2: �û�������,��˶�!" << endl;
		if (err == 3)
			cout << "����3: �û����������˶�!" << endl;
		if (err == 4)
			cout << "����4: ���鸽��Ŀ¼�Ƿ���ȷ���Լ��ļ��Ƿ����!" << endl;
	}
	system("pause");
	return 0;
}