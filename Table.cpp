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
			printf("�����������������룺");
			cin.clear();
			cin.sync();//����� 
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
		printf("1.���ؿ��޷�����PI\n");
		printf("2.����������PI\n"); 
		printf("3.�������룬�˳�����\n\n");
		printf("Please choose the method you like:");
		int a;
		a = input();
		switch(a)
		{
			case 1:
				printf("==========ִ�����ؿ��޷�����PI==========\n");
				printf("��������Դ������Ƽ�1e5~1e9��:");
				monte_carlo(input());
				break;
			case 2:
				printf("==========ִ�м���������PI==========\n");
				series(); 
				break;
			case 3:
				return ;
			default:
				printf("�������������1~3֮�������:"); 
		}
	}
}

