# include <iostream>

using namespace std;

/*

2016年10月9日14:32:00
数字三角形问题

描述:给定一个由n行数字组成的数字三角形如下图所示。试设计一个算法，
计算出从三角形的顶至底的一条路径，使该路径经过的数字总和最大。

样例输入
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

样例输出
30
*/

const int M=100;
int n;
int a[M][M];
int func()
{
  int i,j;
 for(i=n-1;i>=1;i--)
 {
	  for(j=1;j<=i;j++)
	  {
		   if(a[i+1][j]>a[i+1][j+1])
			   a[i][j]+=a[i+1][j];
		   else 
			   a[i][j]+=a[i+1][j+1]; 
	  }
 }
  return a[1][1];
}

int main(void)
{
	int i,j,max;
    cin>>n;
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
    max=func();
    cout<<max<<endl;
	system("pause");
	return 0;
}