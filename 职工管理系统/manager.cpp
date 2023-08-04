#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//获取个人信息
void Manager::showInfo()
{
	cout << "职工编号:" << this->m_Id;
	cout << "\t职工姓名:" << this->m_Name;
	cout << "\t岗位:" << this->getDeptName();
	cout << "\t职责：完成老板指定的任务并且下发任务给普通员工" << endl;
}
//获取岗位信息
string Manager::getDeptName()
{
	return string("经理");
}
