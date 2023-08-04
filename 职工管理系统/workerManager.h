#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"

#define FILENAME "empFile.txt"



class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	
	//显示菜单
	void Show_Menu();

	///退出函数
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工指针
	Worker** mEmpArray;

	//判断是否存在员工
	bool IsEmp(int id);

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsempt;

	//获取文件中的记录数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示当前所有职工信息
	void Show_Emp();

	//删除职工信息前先判断职工是否存在
	int IsExist(int id);
	//删除职工信息
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//析构函数
	~WorkerManager();
};
