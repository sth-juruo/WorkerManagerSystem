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
	int m_EmpNum;//������ְ������
	worker** m_EmpArray;//����ָ��
	//���캯��
	WorkerManage();
	//��������
	~WorkerManage();
	void show_menu();
	void add_emp();
	void save();
};
