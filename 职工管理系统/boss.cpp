#include "boss.h"
boss::boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void boss::showinfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getd_name()
		<< " \t岗位职责：派发任务给员工和经理" << endl;
}
string boss::getd_name()
{
	return string("老板");
}