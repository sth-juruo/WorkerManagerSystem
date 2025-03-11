#include "workermanage.h"
WorkerManage:: WorkerManage()
{
	m_EmpArray = NULL;
	m_EmpNum = 0;
}
WorkerManage::~WorkerManage()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
	}
}
void WorkerManage::show_menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManage::save()
{
	ofstream ofs;
	ofs.open("empfile.txt", ios::out);
	if (ofs.is_open() == 0)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->d_id << " "
			<< m_EmpArray[i]->m_id << " "
			<< m_EmpArray[i]->m_name << endl;
	}
	ofs.close();
}
void WorkerManage:: add_emp()
{
	int addnum, newsize;
	cout << "������Ҫ���ӵ�Ա������" << endl;
	cin >> addnum;
	if (addnum > 0)
	{
		newsize = addnum + m_EmpNum;
		worker** newspace = new worker * [newsize];
		//��ԭ���ݰ��˹���
		if (m_EmpNum > 0)
		{
			for (int i = 0; i <= m_EmpNum - 1; i++)
			{
				newspace[i] = m_EmpArray[i];
			}
		}
		//����³�Ա
		for (int i = 0; i <= addnum - 1; i++)
		{
			int id;
			string name;
			int selct;
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			worker* newworker=NULL;
			cin >> selct;
			if (selct == 1)
			{
				newworker = new employee(id, name, selct);
			}
			else if (selct == 2)
			{
				newworker = new manage(id, name, selct);
			}
			else if (selct == 3)
			{
				newworker = new boss(id, name, selct);
			}
			newspace[m_EmpNum + i] = newworker;
		}
		delete[] m_EmpArray;
		m_EmpNum = newsize;//������������
		m_EmpArray = newspace;
		save();
		cout << "�ɹ����" << addnum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
}
