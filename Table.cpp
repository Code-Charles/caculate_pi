#include "Methods.h" 
 
unsigned long long input()
{	
	using namespace std;
	while(1)
	{	
		unsigned long long  a;
		cin>>a;
		string s = to_string(a);
		
		if((!std::cin)||(a<=0)||(s.size()>19))
		{
			printf("输入有误！请重新输入：");
			cin.clear();
			cin.sync();//清空流 
		}
		else
		{	
			return a;
		 } 
	}	
}

void table()
{
	printf("==========This is a program for caculating PI==========\n");
	while(1)
	{
		printf("----------------------------------------------------\n");
		printf("1.蒙特卡罗法计算PI\n");
		printf("2.级数法计算PI\n"); 
		printf("3.放弃输入，退出程序\n\n");
		printf("Please choose the method you like:");
		int a;
		a = input();
		switch(a)
		{
			case 1:
				printf("==========执行蒙特卡罗法计算PI==========\n");
				printf("请输入测试次数（推荐1e5~1e9）:");
				monte_carlo(input());
				break;
			case 2:
				printf("==========执行级数法计算PI==========\n");
				series(); 
				break;
			case 3:
				return ;
			default:
				printf("输入错误，请输入1~3之间的整数:"); 
		}
	}
}

