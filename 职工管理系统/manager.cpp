#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ȡ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����:" << this->m_Id;
	cout << "\tְ������:" << this->m_Name;
	cout << "\t��λ:" << this->getDeptName();
	cout << "\tְ������ϰ�ָ�����������·��������ͨԱ��" << endl;
}
//��ȡ��λ��Ϣ
string Manager::getDeptName()
{
	return string("����");
}
