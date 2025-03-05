#include "workermanage.h"
int main()
{
	WorkerManage mainwm;
	int choice = 0;
	bool problemflag = 0;//在用户给出错误输入码时，提供提示
	while (1)
	{
		if (problemflag == 0) mainwm.show_menu();
		else problemflag = 0;
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出
			cout << "欢迎下次使用" << endl;
			return 0;
		case 1: //添加职工
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
			problemflag = 1;
			break;
		}
	}
	return 0;
}