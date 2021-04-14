#include<thread>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<windows.h>
#include<cmath>
unsigned long long  input(); //自定义输入函数，获取ull整数 
void table();                //菜单 
void monte_carlo(unsigned long long times); //蒙特卡洛法估算π 
void series();               //级数法估算π 

