#include "empolyee.h"
employee::employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void employee::showinfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getd_name()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}
string employee::getd_name()
{
	return string("员工");
}