#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

//Ա����
class Employee :public Worker
{
public:
	//���캯��
	Employee(int id, string name, int dId);
	//��дworker����ʾ������Ϣ����
	virtual void showInfo();
	//��дworker���ȡְ����λ���Ƶķ���
	virtual string getDeptName();

};