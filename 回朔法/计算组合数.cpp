# include <iostream>

using namespace std;

/*
2016年11月25日16:45:07
计算组合数
找出m个自然数(1,2,3,…,m)中n个数的组合。
要求：    
输入：m,n＝5  3
输出：
123
124
125
134
135
145
234
235
245
345
共10种


设（x1,x2,  ……,xn）一组解
约束条件：
显约束：1≤xi≤m
隐约束：x1＜x2＜ ……＜xn
			        i≤ xi ≤m－n＋i 
即： xi-1 ＜ xi ≤m－n＋i 

*/
int m,n;      //总共m个数,n个数
int *x;       //一个组合
int count=0;  //排列个数
int i;  //下标

//输出一个组合
void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
}

//回朔法
void backtrack(int i){
	if (i>n) output();   //i>n   则输出
	else
		for (int j=x[i-1]+1;j<=m-n+i;j++)   //从x[i-1]+1开始
		{
			x[i]=j;   //让自己比上一个数大
			backtrack(i+1);   //+1  回朔
		} 
}

int main(void)
{
	cout<<endl<<"Please input m,n(m>0) &&(n>0) &&(m>=n))"<<endl;
	do {
		cin>>m>>n;
	}while (!((m>0) &&(n>0) &&(m>=n)));
	x=new int [n+1];
	x[0]=0;
	count=0;
	backtrack(1);
	cout<<endl<<"Total:"<<count<<endl;
	system("pause");
	return 0;
}