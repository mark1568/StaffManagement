#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	//��ȡ������Ϣ
	virtual void showInfo();
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};
