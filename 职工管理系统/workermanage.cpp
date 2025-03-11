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
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManage::save()
{
	ofstream ofs;
	ofs.open("empfile.txt", ios::out);
	if (ofs.is_open() == 0)
	{
		cout << "打开文件失败" << endl;
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
	cout << "请输入要增加的员工数量" << endl;
	cin >> addnum;
	if (addnum > 0)
	{
		newsize = addnum + m_EmpNum;
		worker** newspace = new worker * [newsize];
		//将原数据搬运过来
		if (m_EmpNum > 0)
		{
			for (int i = 0; i <= m_EmpNum - 1; i++)
			{
				newspace[i] = m_EmpArray[i];
			}
		}
		//添加新成员
		for (int i = 0; i <= addnum - 1; i++)
		{
			int id;
			string name;
			int selct;
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
		m_EmpNum = newsize;//更新数组数据
		m_EmpArray = newspace;
		save();
		cout << "成功添加" << addnum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
}
