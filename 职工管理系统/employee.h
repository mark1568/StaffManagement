#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

//员工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id, string name, int dId);
	//重写worker类显示个人信息方法
	virtual void showInfo();
	//重写worker类获取职工岗位名称的方法
	virtual string getDeptName();

};