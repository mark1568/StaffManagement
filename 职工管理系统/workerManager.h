#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"

#define FILENAME "empFile.txt"



class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	
	//��ʾ�˵�
	void Show_Menu();

	///�˳�����
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ��ָ��
	Worker** mEmpArray;

	//�ж��Ƿ����Ա��
	bool IsEmp(int id);

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsempt;

	//��ȡ�ļ��еļ�¼��
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾ��ǰ����ְ����Ϣ
	void Show_Emp();

	//ɾ��ְ����Ϣǰ���ж�ְ���Ƿ����
	int IsExist(int id);
	//ɾ��ְ����Ϣ
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//��������
	~WorkerManager();
};
