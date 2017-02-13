#include <iostream>

using namespace std;

/*
2016年11月3日10:49:53
 
最优装载
有一批集装箱要装上一艘载重量为c的轮船，其中集装箱i的重量为wi （1≤i≤n） 。
最优装载问题要求确定在装载体积不受限制的情况下，将尽可能多的集装箱装上轮船。

解决方案：
船可以分步装载，每步装一个货箱，且需要考虑装载哪一个货箱。
贪心准则：
从剩下的货箱中，选择重量最小的货箱。
这种选择次序可以保证所选的货箱总重量最小，从而可以装载更多的货箱。

例如：
n ＝8
w＝[100,200,50,90,150,50,20,80], c＝400。
按照重量贪心原则，确定装载方案。
解：
所考察货箱的次序 :7, 3,  6,  8, 4, 1, 5,  2
最优解x=[ 1, 0, 1, 1,  0, 1, 1, 1]
*/

int n=8;
int w[] = {100,200,50,90,150,50,20,80};
int x[8]; 
int c=400;
//记录那个货物的下标,排序之后是货物重量从小到大的顺序 
int *t = new int[n];   

//排序   
//参数:重量, 记录那个货物的下标,数量 
template<class Type> 
void Sort(Type w[],int t[],int n) 
{
	int i,j;
	int temp;
	for(i=0; i<n; i++)
	{
		t[i] = i;   //默认下标是自己那个位置 
	} 
	for(i=0; i<n-1; i++)
	{
		int k=i;
		for(j=i+1; j<n; j++)   //从第二个元素往后面找,找到最小值,记录下标 
		{
			if(w[t[j]]<w[t[k]])   //w[t[k]]是上一次的最小值 
			{
				k = j;
			}
		}
		if(t[k]!=t[i])
		{
			temp = t[k];
			t[k] = t[i];
			t[i] = temp;
		}
	} 
}

//贪心算法
//参数: 记录是否装这个货物,重量,总载重,货物个数 
template<class Type>
void Loading(int x[],Type w[],Type c,int n)
{
	
	Sort(w,t,n);
	for(int i=0; i<n; i++)
	{
		x[i] = 0;  //初始化x[i],全部没装 
	} 
	for(int i=0; i<n && w[t[i]]<=c; i++)   //判断是否能继续装下该货物 
	{
		x[t[i]] = 1;     //标记那个货物已被装 
		c -= w[t[i]];   //装了一个货物之后,载重量减少 
	} 
} 

int main(void)
{
	Loading(x,w,c,n);
	
	//
	cout<<"重量:"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<w[i]<<" ";
	}
	cout<<endl;
	cout<<"t[i]"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<t[i]<<" ";
	}
	
	
	return 0;
}