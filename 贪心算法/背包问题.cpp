#include <iostream>

using namespace std;

/*
2016年11月3日9:55:27 
背包问题 
给定n个物品和一个背包，物品 i 的重量为wi ,其价值为vi ,背包的容量为c
如何装物品，使得装入背包中物品总价值最大
可以拆分物品 
*/

int M = 50;        //背包容量 
float v[] = {60,120,100};    //物品价值 
float w[] = {10,30,20};    //物品重量 
int n = 3;    //物品数量 
float x[3];

//排序  按照价值密度 
void Sort(int n,float v[],float w[])
{
	float tempV,tempW;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(v[i]/w[i] > v[j]/w[j])
			{
				tempV = v[i];
				v[i] = v[j];
				v[j] = tempV;
				
				tempW = w[i];
				w[i] = w[j];
				w[j] = tempW;
			}
		} 
	} 
}

//贪心算法   参数:长度,背包容量,价值,重量,是否装(数组,0或者1) 
void Knapsack(int n,float M,float v[],float w[],float x[])
{
	Sort(n,v,w);  //根据价值密度排序
	int i;
	for(i = 0; i<n; i++)   //初始化为0 
	{
		x[i] = 0; 
	}
	float c = M;
	for(i=0; i<n; i++)
	{
		if(w[i]>c)
		{
			break; 
		}
		x[i] = 1;   //当前物品放入背包 
		c -= w[i];  //背包可装容量减少 
	} 
	
	//最后可以装下的一件东西,装不完
	if(i<n) 
	{
		x[i] = c/w[i];    //只装下这东西的一部分 
	}
} 

int main(void)
{
	Knapsack(n,M,v,w,x);
	cout<<"重量"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<w[i]<<" "; 
	}
	cout<<endl<<"价值"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<v[i]<<" "; 
	}
	cout<<endl<<"x[i]"<<endl;
    for(int i=0; i<n; i++)
	{
		cout<<x[i]<<" "; 
	}
	return 0;
}
