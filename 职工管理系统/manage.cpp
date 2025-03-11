#include "manage.h"
manage::manage(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void manage::showinfo()
{
	cout << "职工编号： " << this->m_id
		<< " \t职工姓名： " << this->m_name
		<< " \t岗位：" << this->getd_name()
		<< " \t岗位职责：完成老板任务，派发任务给员工" << endl;
}
string manage::getd_name()
{
	return string("经理");
}