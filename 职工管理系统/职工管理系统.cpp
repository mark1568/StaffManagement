#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "Worker.h"
#include "manager.h"
#include "boss.h"




int main()
{

	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "输入想要执行的功能:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			system("cls");
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:

			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}
