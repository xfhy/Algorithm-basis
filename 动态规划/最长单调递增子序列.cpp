# include <iostream>

using namespace std;

/*
2016年10月9日13:38:58
最长递增子序列
求一个正整数序列的最长单调自增子序列，子序列不要求是连续的。例如
Input：5
5 2 4 3 1
Output：2

一,动态规划法:
设f(i)表示L中以ai为末元素的最长递增子序列的长度。则有如下的递推方程：
这个递推方程的意思是，在求以ai为末元素的最长递增子序列时，
找到所有序号在L前面且小于ai的元素aj，即j<i且aj<ai。如果这样的元素存在，
那么对所有aj,都有一个以aj为末元素的最长递增子序列的长度f(j)，把其中最大的f(j)选出来，
那么f(i)就等于最大的f(j)加上1，即以ai为末元素的最长递增子序列
，等于以使f(j)最大的那个aj为末元素的递增子序列最末再加上ai；如果这样的元素不存在
，那么ai自身构成一个长度为1的以ai为末元素的递增子序列。

public void lis(float[] L)
  {
         int n = L.length;
         int[] f = new int[n];//用于存放f(i)值；
         f[0]=1;//以第a1为末元素的最长递增子序列长度为1；
         for(int i = 1;i<n;i++)//循环n-1次
         {
                f[i]=1;//f[i]的最小值为1；
                for(int j=0;j<i;j++)//循环i 次
                {
                       if(L[j]<L[i]&&f[j]>f[i]-1)
                              f[i]=f[j]+1;//更新f[i]的值。
                }
         }
         System.out.println(f[n-1]);            
              }
*/


int a[10] = {12,21,23,423,4,41,4,1,51,51};
//f[i] 1 2 3 4 1 4 1 1 5 5

//从前往后
void hehe(int n){
	int f[10]={0};  //f[]数组记录,到a[i]这里最长的子序列   f[]数组最大值就是想要的结果
	f[0] = 1;   //第一位肯定是1,前面没有数
	for(int i = 1 ; i < n ; i++ )
	{
		f[i] = 1;
		for(int j = 0 ; j < i ; j++)  //只判断a[i]前面的数
		{
			//如果前面的数比当前数小  且   当前数前面的最长子序列+1比当前数的最长子序列大
           if(a[j] < a[i] && f[j]+1 > f[i])//等号有没有要视题目而定
			{
				f[i] = f[j] +1;
			}
		}
	}

	int max=f[0];
	for(int i=0; i<10; i++)
	{
		//cout<<f[i]<<" ";
		if(max < f[i])
		{
			max = f[i];
		}
	}
	cout<<"最长递增子序列为:"<<max<<endl;
}

int main(void)
{
	hehe(10);
	system("pause");
	return 0;
}