#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include "empolyee.h"
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
};
