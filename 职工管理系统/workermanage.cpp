#include "workermanage.h"
WorkerManage:: WorkerManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (ifs.is_open() != 1)
	{
		cout << "初始化文件不存在" << endl;
		m_EmpArray = NULL;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;//刷新流状态
	//存在但文件为空
     if (ifs.eof()==1)
	{
		cout << "初始化文件为空" << endl;
		m_EmpArray = NULL;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}	 
	 init_Emp();
}
WorkerManage::~WorkerManage()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
	}
}
//获取文件中员工的人数
int WorkerManage::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int did, id;
	int num = 0;
	string name;
	while (ifs >> did && ifs >> name && ifs >> id)
	{
		num++;
	}
	ifs.close();
	return num;
}
//通过文件初识化员工
void WorkerManage::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	m_EmpNum = get_EmpNum();
	worker** newspace = new worker * [m_EmpNum];
	int did, id;
	int index = 0;
	string name;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;
		if (did == 1)
		{
			worker = new employee(id, name, 1);
		}
		else if (did == 2)
		{
			worker = new manage(id, name, 2);
		}
		else if (did == 3)
		{
			worker = new boss(id, name, 3);
		}
		newspace[index] = worker;
		index++;
	}
	m_EmpArray = newspace;
	m_FileIsEmpty = false;
	ifs.close();
}
//开始菜单
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
//将数据保存到文件里
void WorkerManage::save()
{
	ofstream ofs;
	ofs.open("empfile.txt", ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_id << " "
			<< m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->d_id << endl;
	}
	ofs.close();
}
//增加员工
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
			int select;
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			worker* newworker=NULL;
			cin >> select;
			while (1)
			{
				if (select == 1)
				{
					newworker = new employee(id, name, select);
					break;
				}
				else if (select == 2)
				{
					newworker = new manage(id, name, select);
					break;
				}
				else if (select == 3)
				{
					newworker = new boss(id, name, select);
					break;
				}
				else
				{
					cout << "输入有误，请重新输入" << endl;
					cin >> select;
				}

			}
			newspace[m_EmpNum + i] = newworker;
		}
		delete[] m_EmpArray;
		m_EmpNum = newsize;//更新数组数据
		m_EmpArray = newspace;
		save();
		m_FileIsEmpty = false;
		cout << "成功添加" << addnum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
}
//显示员工
void WorkerManage::show_Emp()
{
	if (m_FileIsEmpty == true)
	{
		cout << "文件为空" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->showinfo();
		}
		return;
	}
}
//以id查找员工，并返回其在数组中的下标，若不存在则返回-1
int WorkerManage::find_Emp(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (id == m_EmpArray[i]->m_id)
		{
			index = i;
			return index;
		}
	}
	return index;
}
//删除员工
void WorkerManage::del_Emp()
{
	int id = 0;
	cout << "请输入要删除的员工的id" << endl;
	cin >> id;
	int index = find_Emp(id);
	if (index == -1)
	{
		cout << "员工不存在" << endl;
		return;
	}
	else
	{
		for (int i = index; i < m_EmpNum - 1; i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		if (m_EmpNum == 0) m_FileIsEmpty = true;
		this->save();
		cout << "删除成功" << endl;
		return;
	}
}
//修改员工
void WorkerManage::Mod_Emp()
{
	cout << "请输入要修改的员工的id" << endl;
	int mod_id = -1;
	cin >> mod_id;
	int index = find_Emp(mod_id);
	if (index != -1)
	{
		delete m_EmpArray[index];
		int id;
		string name;
		int select;
		cout << "请输入新职工编号：" << endl;
		cin >> id;
		cout << "请输入新职工姓名：" << endl;
		cin >> name;
		cout << "请选择该职工的岗位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		worker* newworker = NULL;
		cin >> select;
		while (1)
		{
			if (select == 1)
			{
				newworker = new employee(id, name, select);
				break;
			}
			else if (select == 2)
			{
				newworker = new manage(id, name, select);
				break;
			}
			else if (select == 3)
			{
				newworker = new boss(id, name, select);
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
				cin >> select;
			}
		}
		m_EmpArray[index] = newworker;
		save();
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "未找到此员工" << endl;
	}
}
//以id或者name查找员工，并输出其信息
void WorkerManage::sort_Emp()
{
	if (m_FileIsEmpty == true)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	cout << "请输入查找的方式：" << endl;
	cout << "1、按职工编号查找" << endl;
	cout << "2、按姓名查找" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		int id;
		cout << "请输入要查找的员工id" << endl;
		cin >> id;
		int index = find_Emp(id);
		if (index != -1)
		{
			cout << "查找成功" << endl;
			m_EmpArray[index]->showinfo();

		}
		else
		{
			cout << "查无此人" << endl;
		}
		return;
	}
	/*else if (select == 2)
	{

	}*/
	else
	{
		cout << "输入有误" << endl;
		return;
	}
}