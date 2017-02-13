# include <iostream>
# include <math.h>

using namespace std;

/*
2016年11月25日22:07:22
在n×n格的棋盘上放置彼此不受攻击的n个皇后。
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n后问题等价于在n×n格的棋盘上放置n个皇后，
任何2个皇后不放在同一行或同一列或同一斜线上。

一维数组求解

分析
解向量：(x1, x2, … , xn)    放到多少列
约束条件
显约束： 1≤xi≤n
隐约束：                             	
不同列：Xi 不等于 Xk		
不处于同一正、反对角线：|i－k| 不等于 |xi-xk|   (即斜率不为1   45°角)

*/
int n,i,count,*x;

//输出一个组合
void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
}

bool check(int i){
  for (int k=1;k<i;k++) 
         if (x[k]==x[i] || abs(x[k]-x[i])==abs(k-i))   //斜率
	  return false;
  return true;
}

void queue(int i){
   if (i>n) output();
   else 
	for (int j=1;j<=n;j++){
	  x[i]=j;
	 if (check(i)) queue(i+1);
    }
}


void main(){
   cout<<endl<<"Please input n=";
   cin>>n;
   x=new int [n+1];
   count=0;
   queue(1);
   cout<<endl<<"Total ="<<count<<endl;
   system("pause");
}
