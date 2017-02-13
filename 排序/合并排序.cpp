# include <iostream>

using namespace std;

/*
2016年10月2日8:13:44
合并排序

合并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）
的一个非常典型的应用。
合并排序法是将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列分为若干个子序列，
每个子序列是有序的。然后再把有序子序列合并为整体有序序列。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
若将两个有序表合并成一个有序表，称为2-路归并。合并排序也叫归并排序。

合并排序最大的优点是它的时间复杂度为O(nlgn)，这个是我们之前的选择排序和插入排序所达不到的。
他还是一种稳定性排序，也就是相等的元素在序列中的相对位置在排序前后不会发生变化。
他的唯一缺点是，需要利用额外的N的空间来进行排序
*/

int a[10] = {2,1,34,21,35,23,12,32,42,12};   //原始数组
int b[10] = {0};  //辅助数组

void Merge(int array1[],int start,int mid,int end)
{
	int i=start,j=mid+1;
	for(int k=start; k <= end; k++)  //将元素拷贝到辅助数组中
	{
		b[k] = a[k];
	}

	//然后按照规则将数据从辅助数组中拷贝回原始的array中
	//相当于合并左右两边的数组,根据比较,放在合适的位置
	for(int k=start; k <= end; k++)  
	{
		if(i>mid)   //如果左边元素没了， 直接将右边的剩余元素都合并到到原数组中
		{
			a[k] = b[j++];
		}
		else if(j>end) //如果右边元素没有了，直接将所有左边剩余元素都合并到原数组中
		{
			a[k] = b[i++];
		}
		else if(b[i]<b[j]) //如果左边右边小，则将左边的元素拷贝到原数组中
		{
			a[k] = b[i++];
		}
		else 
		{
			a[k] = b[j++];
		}
	}
}

void Sort(int array1[],int start,int end)
{
	if(start >= end)    //如果下标大于上标,则返回
	{
		return ;
	}
	int mid = start + (end-start)/2;  //中间下标,平分数组
	Sort(array1,start,mid);  //循环对左侧元素排序
	Sort(array1,mid+1,end);  //循环对右侧元素排序
	Merge(array1,start,mid,end);   //对左右排好序的序列进行合并
}

int main(void)
{
	Sort(a,0,9);
	for(int i=0; i<10; i++){
		cout<<a[i]<<" ";
	}
	system("pause");
	return 0;
}