#include "empolyee.h"
employee::employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void employee::showinfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getd_name()
		<< " \t��λְ����ɾ�����������" << endl;
}
string employee::getd_name()
{
	return string("Ա��");
}