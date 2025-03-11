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
	//构造函数
	WorkerManage();
	//析构函数
	~WorkerManage();
	void show_menu();
	void add_emp();
	void save();
};
