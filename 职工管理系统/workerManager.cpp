#include "workerManager.h"
#include "employee.h"
#include "Worker.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1.�ļ�������ʱ
	
	//�ж��ļ��Ǵ���
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ��
		this->m_EmpNum = 0;
		this->mEmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsempt = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	//eof()����true�����ļ�������
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ��
		this->m_EmpNum = 0;
		this->mEmpArray = NULL;

		this->m_FileIsempt = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼��������

	int num = this->get_EmpNum();
	cout << "ְ����Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->mEmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ�ŵ�������
	this->init_Emp();

	//���Դ��룺(ֻ�Ǹ�����)
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְԱ���:" << this->mEmpArray[i]->m_Id
	//		<< "����:" << this->mEmpArray[i]->m_Name
	//		<< "���ű��:" << this->mEmpArray[i]->m_DeptId << endl;
	//}
}

//��ʾ����
void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**************��ӭʹ��ְ������ϵͳ************" << endl;
	cout << "**************   0.�˳��������   ************" << endl;
	cout << "**************   1.����ְ����Ϣ   ************" << endl;
	cout << "**************   2.��ʾְ����Ϣ   ************" << endl;
	cout << "**************   3.ɾ��ְ����Ϣ   ************" << endl;
	cout << "**************   4.�޸�ְ����Ϣ   ************" << endl;
	cout << "**************   5.����ְ����Ϣ   ************" << endl;
	cout << "**************   6.���ձ������   ************" << endl;
	cout << "**************   7.��������ĵ�   ************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//�˳�����
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


//�ж��Ƿ���ڳ�Ա
bool WorkerManager::IsEmp(int id)
{
	bool isid = true;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->mEmpArray[i]->m_Id == id)
		{
			isid = false;
		}
	}
	return isid;
}

//��ӳ�Ա
void WorkerManager::Add_Emp()
{
	cout << "����Ҫ��ӵ�ְ������:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker* [newSize];
		//��ԭ�ռ����ݿ������¿ռ�
		if (this->m_EmpNum != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->mEmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			bool ret = this->IsEmp(id);
			if(ret)
			{
				cout << "�������" << i + 1 << "��ְ��������" << endl;
				cin >> name;
				cout << "��ѡ��ְ����λ" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> dSelect;

				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
				}

				//��������ְ��ְ�𱣴���������
				newSpace[this->m_EmpNum + i] = worker;
			}
			else
			{
				cout << "�������ظ��ı��" << endl;
				break;
			}
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->mEmpArray;
		//�����¿ռ�ָ��
		this->mEmpArray = newSpace;

		//����ְ������
		this->m_EmpNum = newSize;

		//�����ļ�Ϊ ��Ϊ��
		this->m_FileIsempt = false;


		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	//����������ز˵�
	system("pause");
	system("cls");
}

//���溯��ʵ��
void WorkerManager::save()
{
	//���ļ�
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->mEmpArray[i]->m_Id << " "
			<< this->mEmpArray[i]->m_Name << " "
			<< this->mEmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��ȡ�ļ������ݸ���
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;//���λ��

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		if (dId == 3)//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->mEmpArray[index] = worker;
		index++;
	}
}

//��ʾְԱ��Ϣ
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->mEmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->mEmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��ְ����Ϣ
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����Ա���ı��" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->mEmpArray[i] = this->mEmpArray[i] + 1;
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "û���ҵ�ָ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "�����޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete  this->mEmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelete = 0;

			cout << "�鵽" << ret << "��Ա�����������µ�Ա����ţ�" << newId << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;
			cout << "�����¸�λ:" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelete;

			Worker* worker = NULL;
			switch (dSelete)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}

			//��������
			this->mEmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ�ָ�����" << endl;
		}
	}
}

//���������������������ͷ�
WorkerManager::~WorkerManager()
{
	if (this->mEmpArray != NULL)
	{
		delete[] this->mEmpArray;
		this->mEmpArray = NULL;
	}
}

