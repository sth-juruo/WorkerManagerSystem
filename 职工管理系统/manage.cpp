#include "manage.h"
manage::manage(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void manage::showinfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getd_name()
		<< " \t��λְ������ϰ������ɷ������Ա��" << endl;
}
string manage::getd_name()
{
	return string("����");
}