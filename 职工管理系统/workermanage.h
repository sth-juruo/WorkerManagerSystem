#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"
#include "empolyee.h"
#include "boss.h"
#include "manage.h"
#define FILENAME "empfile.txt"
using namespace std;
class WorkerManage
{
public:
	int m_EmpNum;//数组中职工数量
	worker** m_EmpArray;//数组指针
	bool m_FileIsEmpty=false;//文件是否为空的标志
	//构造函数
	WorkerManage();
	//析构函数
	~WorkerManage();
	void show_menu();//显示菜单
	void add_emp();//添加员工
	void save();//保存
	int get_EmpNum();//获取文件中员工的人数
	void init_Emp();//用文件初始化员工
	void show_Emp();//显示员工
	int find_Emp(int id);//查找员工
	void del_Emp();//删除员工
	void Mod_Emp();//修改员工
	void sort_Emp();//搜索员工
};
