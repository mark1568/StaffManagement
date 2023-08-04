#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	//获取个人信息
	virtual void showInfo();
	//获取岗位信息
	virtual string getDeptName();
};

