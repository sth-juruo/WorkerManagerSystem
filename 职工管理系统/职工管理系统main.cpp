#include "workermanage.h"
int main()
{
	WorkerManage mainwm;
	int choice = 0;
	while (1)
	{
	    mainwm.show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)  
		{
		case 0://退出
			cout << "欢迎下次使用" << endl;
			return 0;
		case 1: //添加职工
			mainwm.add_emp();
			break;
		case 2: //显示职工
			break;
		case 3: //删除职工
			break;
		case 4: //修改职工
			break;
		case 5: //查找职工
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			cout << "错误的操作码，请重新输入" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}