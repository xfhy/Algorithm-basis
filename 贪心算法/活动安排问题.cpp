#include <iostream>

using namespace std;

/*
2016年11月3日10:28:45
活动安排问题 

n个活动的集合E={1,2,…,n}
每个活动i 要求使用资源的时间：[si, fi)
活动i与活动j是相容的：
若区间[si, fi)与区间[sj, fj)不相交，称活动i与活动j是相容的。
活动安排问题：在所给的活动集合中选出最大的相容活动子集合。即：要求高效地安排一系列争用某一公共资源的活动。

*/

int n = 7;   //活动个数 
int s[] = {1,3,4,5,5,5,6};  //所有活动的开始时间 
int f[] = {4,5,6,7,8,9,10}; //所有活动的结束时间 
bool a[7];   //所有活动被安排情况 

//贪心算法   
//参数:未安排的活动个数,每个活动开始时间,每个活动结束时间,每个活动被安排情况 
int greedySelector(int n,int s[],int f[],bool a[])
{
	a[0] = true;   //第一个活动是直接被安排了的     假设已排好序
	int count = 1; //已经安排的活动个数
	int j=0;       //当前已经安排了的活动的最后时间的下标 
	for(int i=1; i<n; i++)
	{
		//如果当前活动的开始时间比之前安排的最后一个活动的结束时间大,则
		//可以安排 
		if(s[i]>=f[j])
		{
			a[i] = true;   //安排当前活动 
			j = i;         //当前活动为目前最后安排的活动 
			count++;       //被安排的活动数目+1 
		}
		else
		{
			a[i] = false;  //未被安排 
		} 
	} 
	return count;  
} 

int main(void)
{
	for(int i=0; i<n; i++)
	{
		a[i] = false; 
	}
	int count = greedySelector(n,s,f,a);
	
	cout<<"已安排的活动个数"<<count<<endl; 
	
	//被安排的活动如下 
	cout<<"被安排的活动如下 "<<endl; 
	for(int i=0; i<n; i++)
	{
		if(a[i])
		{
			cout<<s[i]<<"~"<<f[i]<<endl; 
		} 
	}
	return 0;
}
