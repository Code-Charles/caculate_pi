#include "Methods.h"

const int THREADS = 100;  //设置100个线程 
unsigned long long success[THREADS];   //存放THREANDS个线程中各自的success 
void monte(unsigned long long times,int thread_id)
{
//	std::cout<<"You are such a loser"<<std::endl;
	float x,y;
	success[thread_id]=0;
	srand((unsigned)time(NULL)*10);    //设置随机数种子 
	for (int i=0;i<times;++i)
	{
/*		if(thread_id==0)
		{
			printf("%.2f%%\n",(i*100.0)/times+0.01);
		}*/
		x = 1.0*rand()/RAND_MAX;
		y = 1.0*rand()/RAND_MAX;
		if(x*x+y*y<1.0)
			++success[thread_id];
	}
	return;
 } 
void monte_carlo(unsigned long long times)
{
	std::thread threads[THREADS];  //创建THREADS个线程 
	std::cout<<"-----Threads are created!-----\n";
	DWORD start = GetTickCount();
	for(int i =0;i<THREADS;++i)
	{
		threads[i] = std::thread(monte,times/THREADS+(times%THREADS >i),i);
		//执行 
	 } 

	for(int i=0;i<THREADS;++i)
	{
		threads[i].join();
	}
	std::cout<<"-----All threads joined!-----\n";
	unsigned long long sum = 0;
	for(int i=0;i<THREADS;++i)
		sum +=success[i];
	DWORD end = GetTickCount();
	std::cout<<"This method costs "<<(end-start)<<" ms\n";
	std::cout<<"THE ESTIMATE OF PI OBTAINED BY Monte Carlo METHOD IS : "\
		<<(float(sum)/times)*4<<std::endl; 
	printf("ACCURATE TO TWO SIGNFICANT DIGITS: %.1f\n\n\n",(float(sum)/times)*4);
	return;
}


