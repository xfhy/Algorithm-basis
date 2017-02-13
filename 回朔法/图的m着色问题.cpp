# include <iostream>

using namespace std;

/*
2016年11月25日21:42:21
图的m着色问题

需要用邻接矩阵

分析：
解向量：(x1, x2, … , xn)
约束条件
显约束：1≤xi≤m
隐约束：顶点i与已着色的相邻顶点k的颜色不重复
                         !  (  (a[k][i]==1) && (x[k]==x[i]) )
算法设计
回溯法

下面演示的是七巧板
*/

int a[7][7] = {
	{0,1,0,0,1,0,1},
	{1,0,0,1,0,1,0},
	{0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,0,0,0,0,1},
	{0,1,0,1,0,0,0},
	{1,0,1,1,1,0,0}
};
int *x;    //解向量
int count=0;
int n=7,m=3;

//检查   相邻的区域是否是相同的颜色
bool check(int i)
{
	for(int k=1; k<i; k++)
	{
		if( (a[k][i]==1) && (x[k]==x[i]) )   //是否相邻           颜色是否相同     
		{
			return false;
		}
	}
	return true;
}

//输出一个组合
void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
}

//尝试着色
void trycolor(int i)
{
	if(i>n)
		output();
	else
	{
		for(int j=1; j<=m; j++)
		{
			x[i] = j;    //尝试着色
			if(check(i))  //检查
				trycolor(i+1);
		}
	}
}

int main(void)
{
	x = new int[n+1];
	count=0;
	trycolor(1);
    cout<<endl<<"Total:"<<count<<endl;
	system("pause");
	return 0;
}