#include "workermanage.h"
int main()
{
	WorkerManage mainwm;
	int choice = 0;
	bool problemflag = 0;//���û���������������ʱ���ṩ��ʾ
	while (1)
	{
		if (problemflag == 0) mainwm.show_menu();
		else problemflag = 0;
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		case 1: //���ְ��
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			cout << "����Ĳ����룬����������" << endl;
			problemflag = 1;
			break;
		}
	}
	return 0;
}