#pragma once
#include <iostream>
#include <string>
using namespace std;
class worker
{
public:
	int m_id;
	string m_name;
	int d_id;
	virtual void showinfo() = 0;
	virtual string getd_name()=0;
};