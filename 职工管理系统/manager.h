#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int dId);
	//��ȡ������Ϣ
	virtual void showInfo();
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};

