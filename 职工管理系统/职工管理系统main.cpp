#include "workermanage.h"
int main()
{
	WorkerManage mainwm;
	int choice = 0;
	while (1)
	{
	    mainwm.show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)  
		{
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
		case 1: //���ְ��
			mainwm.add_emp();
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
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}