#include "boss.h"
boss::boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->d_id = dId;
}
void boss::showinfo()
{
	cout << "ְ����ţ� " << this->m_id
		<< " \tְ�������� " << this->m_name
		<< " \t��λ��" << this->getd_name()
		<< " \t��λְ���ɷ������Ա���;���" << endl;
}
string boss::getd_name()
{
	return string("�ϰ�");
}