#include"Methods.h"

const int THREADS2 = 5;  //设置5个线程 
double block[THREADS2];
void series_shop(int i) 
{
	block[i] = 0;
	float item;
	for(int j =i+1;fabs(1.0/(4*j-3)>1e-6);j+=THREADS2)
	{
		item = 1.0/(4*j-3)-1.0/(4*j-1);
		block[i]+=item;
	}
	return;
}

void series()
{
	std::thread threads[THREADS2];    //创建THREADS2个线程 
	std::cout<<"-----Threads are created!-----\n";
	DWORD start = GetTickCount();
	for(int i =0;i<THREADS2;++i)
	{
		threads[i] = std::thread(series_shop,i);//创建线程
	 } 	
	for(int i=0;i<THREADS2;++i)
	{
		threads[i].join();
	}
	std::cout<<"-----All threads joined!-----\n";
	double sum = 0;
	for(int i=0;i<THREADS2;++i)
		sum +=block[i];
	DWORD end = GetTickCount();
	std::cout<<"This method costs "<<(end-start)<<" ms\n";
	std::cout<<"THE ESTIMATE OF PI OBTAINED BY SERIES METHOD IS : "<<sum*4<<std::endl; 
	printf("ACCURATE TO TWO SIGNFICANT DIGITS: %.1lf\n\n\n",sum*4);
	return;
}
