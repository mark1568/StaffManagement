#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//获取个人信息
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_Id;
	cout << "\t职工姓名:" << this->m_Name;
	cout << "\t岗位:" << this->getDeptName();
	cout << "\t职责：管理公司所有事物" << endl;
}
//获取岗位信息
string Boss::getDeptName()
{
	return string("老板");
}

