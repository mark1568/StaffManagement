#include "workerManager.h"
#include "employee.h"
#include "Worker.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1.文件不存在时
	
	//判断文件是存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化
		this->m_EmpNum = 0;
		this->mEmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsempt = true;
		ifs.close();
		return;
	}

	//2.文件存在，但是数据为空
	char ch;
	ifs >> ch;
	//eof()返回true表明文件读完了
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化
		this->m_EmpNum = 0;
		this->mEmpArray = NULL;

		this->m_FileIsempt = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且记录的有数据

	int num = this->get_EmpNum();
	cout << "职工数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->mEmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存放到数组中
	this->init_Emp();

	//测试代码：(只是个测试)
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职员编号:" << this->mEmpArray[i]->m_Id
	//		<< "姓名:" << this->mEmpArray[i]->m_Name
	//		<< "部门编号:" << this->mEmpArray[i]->m_DeptId << endl;
	//}
}

//显示函数
void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**************欢迎使用职工管理系统************" << endl;
	cout << "**************   0.退出管理程序   ************" << endl;
	cout << "**************   1.增加职工信息   ************" << endl;
	cout << "**************   2.显示职工信息   ************" << endl;
	cout << "**************   3.删除职工信息   ************" << endl;
	cout << "**************   4.修改职工信息   ************" << endl;
	cout << "**************   5.查找职工信息   ************" << endl;
	cout << "**************   6.按照编号排序   ************" << endl;
	cout << "**************   7.清空所有文档   ************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//退出函数
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


//判断是否存在成员
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

//添加成员
void WorkerManager::Add_Emp()
{
	cout << "输入要添加的职工数量:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker* [newSize];
		//将原空间数据拷贝进新空间
		if (this->m_EmpNum != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->mEmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			bool ret = this->IsEmp(id);
			if(ret)
			{
				cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
				cin >> name;
				cout << "请选择职工岗位" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
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

				//将创建的职工职责保存在数组中
				newSpace[this->m_EmpNum + i] = worker;
			}
			else
			{
				cout << "输入了重复的编号" << endl;
				break;
			}
		}

		//释放原有的空间
		delete[] this->mEmpArray;
		//更改新空间指向
		this->mEmpArray = newSpace;

		//更新职工人数
		this->m_EmpNum = newSize;

		//更新文件为 不为空
		this->m_FileIsempt = false;


		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}

	//按任意键返回菜单
	system("pause");
	system("cls");
}

//保存函数实现
void WorkerManager::save()
{
	//打开文件
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->mEmpArray[i]->m_Id << " "
			<< this->mEmpArray[i]->m_Name << " "
			<< this->mEmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

//获取文件中数据个数
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

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;//存放位置

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		if (dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}
		this->mEmpArray[index] = worker;
		index++;
	}
}

//显示职员信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "文件不存在或者为空" << endl;
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

//判断职工是否存在
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

//删除职工信息
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		int id;
		cout << "输入你要删除的员工的编号" << endl;
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "没有找到指定编号" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsempt)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "输入修改的职工编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete  this->mEmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelete = 0;

			cout << "查到" << ret << "号员工，请输入新的员工编号：" << newId << endl;
			cin >> newId;
			cout << "输入新姓名：" << endl;
			cin >> newName;
			cout << "输入新岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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

			//更新数据
			this->mEmpArray[ret] = worker;

			cout << "修改成功" << endl;

			this->save();
		}
		else
		{
			cout << "修改失败，未找到指定编号" << endl;
		}
	}
}

//析构函数将堆区的数据释放
WorkerManager::~WorkerManager()
{
	if (this->mEmpArray != NULL)
	{
		delete[] this->mEmpArray;
		this->mEmpArray = NULL;
	}
}

