#include <iostream>

using namespace std;
 
/*
2016年11月11日12:19:21 
计算排列
如何找出m个自然数(1,2,3,…,m)中n个数的所有排列。
分析
解向量：(x1,x2,  ……,xn）
约束条件：
显约束：1≤xi≤m
隐约束：xi  ≠ xj      ( 1≤i＜j≤n   )
*/

//class My{
//public:
//   static int count;
//};
//int My::count=20;

//int m = 5;
//int n = 3;
//int *x;
//int count = 0;

//void backtrack(int i);
//void output();
//bool check1(int i);
//
//void backtrack(int i)
//{
//	if(i > n)
//	{
//		output();
//	} 
//	else 
//	{
//		for(int j=1; j <= m; j++){
//			x[i] = j;   //将当前数赋值给x[i] 
//			if(check1(i))   //判断之前是否出现过 
//			{
//				backtrack(i+1);  //向下 
//			}
//		}
//	}
//	
//}
//
//输出数组
//void output()
//{
//	count++;
//	cout<<endl;
//	for(int i=1; i<=n; i++){
//		cout<<" "<<x[i];
//	}
//} 
//
////检查之前的是否含有,含有则返回false
//bool check1(int i){
//	for (int k=1;k<i;k++)
//		if (x[k]==x[i]) return false;
//	return true;
//}
//
//int main(void)
//{
//	x=new int [n+1];
//	x[0]=0;
//	backtrack(1);
//	cout<<endl<<"Total:"<<count<<endl;
//	system("pause");
//	return 0;
//}

/*------------------------------下面是为了排列这些数,且不是递归的-------------------------------*/
int m,n;
int *x;       //所有数存在这里
int count=0;  //排列个数
int i;  //下标
bool ok = true;

//判断之前是否已经含有
bool check(int i)
{
	for(int k=1; k<i; k++)
	{
		if(x[k]==x[i]) 
			return false;
	}
	return true;
}

void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
} 

//回退
void change()
{
	//回退
	while(x[i]==m)
	{
		i--;
	}
	x[i]++;   //退回到可以前进的那个点+1
}

//延伸
void extend()
{
	i++;
	x[i] = 1;  //
}

int main(void)
{
	cin>>m>>n;
	x = new int[n+1];
	count=0;
	i=0;
	x[i]=0;
	ok = true;

	do
	{
		if(ok)
		{
			if(i==n)
			{
				output();
				change();
			} else {
				extend();
			}
		} else {
			change();
		}
		ok = check(i);
	}while(i>0);

	system("pause");
	return 0;
}

