#include <iostream>

using namespace std;

/*
2016年10月23日12:22:44
最长公共子序列 
什么是最长公共子序列(可以不是连续的)呢？举个简单的例子吧，一个数列S，
若分别是两个或多个已知序列的子序列，且是所有符合条件序列中最长的，
则S称为已知序列的最长公共子序列。

  举例如下，如：有两个随机数列，1 2 3 4 5 6 和 3 4 5 8 9，
  则它们的最长公共子序列便是：3 4 5。
*/

int **c = NULL;   //c[m][n]是最长公共子序列的长度
char **b = NULL;   //二维数组  全局的
int row=3;   //行
int col=4;   //列
char x[] = {'B','C','B','D','F'};
char y[] = {'A','B','C','B','D','A','B'};

/*
计算最长公共子序列的动态规划算法
参数:
m:A序列的长度
n:B序列的长度
x:A序列(数组)
y:B序列(数组)
c:c[i][j]:存储X[i]与Y[j]最长公共子序列的长度
b:b[i][j]:记录c[i][j]是从哪一个子问题了解到的(1:左上角那个,2:上边那个,3:左边那个)
*/
void LCSLength(int m,int n,char *x,char *y,int ** c){
	int i,j;

	//初始化,将第一行第一列初始化为0(长度为0的序列与其他任何序列的最长公共子序列为0)
	for(i=0; i<=m; i++){
		c[i][0] = 0;
	}
	for(j=0; j<=n; j++){
		c[0][j] = 0;
	}
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(x[i]==y[j]){   //当遇到两个字符相等时,则将长度+1
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			} else if(c[i-1][j]>=c[i][j-1]){  //上边大于左边
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
	}
}

/*
打印最长公共子序列
*/
void LCS(int i,int j,char *x,char **b){
	if(i==0 || j==0)   //递归出口,当遇到边界时
		return ;
	if(b[i][j]==1){    //如果是1,则说明是从左上角下来的
		LCS(i-1,j-1,x,b);
		cout<<x[i];
	} else if(b[i][j]==2){  //如果是2,则是从上边下来的
		LCS(i-1,j,x,b);
	} else {
		LCS(i,j-1,x,b);
	}
}

//动态生成二维数组 
void makeArray(int row,int col)
{
	b = new char *[row+1];
	c = new int*[row+1];
	for(int i=0; i<row+1; i++){
		b[i] = new char[col+1];
		c[i] = new int[col+1];
	}	
} 

//二维数组 使用并输出
void printCout(int row,int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			b[i][j] = i*j;
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl; 
	}
} 

int main(void)
{
	makeArray(row,col);
	LCSLength(row,col,x,y,c);
	LCS(row,col,x,b);
	system("pause");
	return 0;
}
