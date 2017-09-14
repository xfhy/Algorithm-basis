# include <iostream>
# include <stdlib.h>
# include <time.h>

using namespace std;

/*
2016年10月2日12:29:24
快速排序
 a.最坏情况(O(n^2))   eg:已经有序
 b.平均(O(nlogn))

基本思想:1．先从数列中取出一个数作为基准数。
         2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
         3．再对左右区间重复第二步，直到各区间只有一个数。

基准数的选取:
 a.传统的方法(a[0]) 可能最快
 b.随机选取
 c.中值
*/

void Swap(int &c,int &d);
int Rondom(int p,int r);
int RandomizedPartition(int a[],int p,int r);
int Partition(int a[],int low,int high);
void Sort(int a[],int low,int high);


int a[10] = {31,31,31,2,1,41,41,435,451,51};   //原始待排数据

//交换2个数
void Swap(int &c,int &d)
{
	int temp = c;
	c = d;
	d = temp;
}

//产生随机数
int Rondom(int p,int r)
{
	srand((unsigned)time(NULL));
	return rand()%(r-p)+p;
}

//随机选择基准数,放在该放的位置,并返回该数的索引
int RandomizedPartition(int a[],int p,int r)
{
	int i = Rondom(p,r);
	Swap(a[i],a[p]);   //随机产生一个数作为基准数
	return Partition(a,p,r);   //跑一趟,让该基准数放在合适的位置,并返回该位置的索引
}

//随机选择一个数,作为基准的快速排序
void RandomSort(int a[],int low,int high)
{
	if(low < high)
	{
		int pivotloc = RandomizedPartition(a,low,high);    //放置一个数在合适的位置,获取该数的下标
		Sort(a,low,pivotloc-1);       //分治法      中间那个数(pivotloc)已经排列好了,已经放在了合适的位置
		Sort(a,pivotloc+1,high);
	}
}

//快速排序的一趟循环
//算法：将一个数，比它小的放到该数的前面，比它大的放到该数的后面   
//这里的基准数是最传统的选法,直接将第一个作为基准数
int Partition(int a[],int low,int high)
{
	int pivotkey = a[low];   //基准数
	while(low < high)  //快速将元素放到适当的位置（前小后大）
	{
		while(low < high && a[high]>=pivotkey)  //从 后往前循环，遇到比pivotkey小的，就把该值放到前面去
		{
			high--;
		}
		a[low] = a[high];  //退出循环时，a[high]<=pivotkey

		while(low < high && a[low]<=pivotkey)
		{
			low++;
		}
		a[high] = a[low];  //退出循环时，a[low]>=pivotkey
	}
	a[low] = pivotkey;  //回归
	return low;
}

//数组快速排序
void Sort(int a[],int low,int high)
{
	if(low < high)
	{
		int pivotloc = Partition(a,low,high);    //放置一个数在合适的位置,获取该数的下标
		Sort(a,low,pivotloc-1);       //分治法      中间那个数(pivotloc)已经排列好了,已经放在了合适的位置
		Sort(a,pivotloc+1,high);
	}
}

/*
线性选择算法
    选择问题定义，实际上所有处理均可以推广到集合中包含重复数值的情形。
    输入：一个包含n个（不同的）数的集合A和一个数i，1<=i<=n。
    输出：元素x属于A，它恰大于A中其他的i-1个元素。
*/

int main(void)
{
	//Sort(a,0,9);   //传统的快速排序
	RandomSort(a,0,9);  //随机选择基准数的快速排序(可能有最坏情况)

	//输出数组
	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" ";
	}

	system("pause");
	return 0;
}