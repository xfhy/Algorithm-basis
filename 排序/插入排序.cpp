# include <iostream>

using namespace std;

/**
description 插入排序 
author xfhy
create at
*/

/**
插入排序 
参数:待排序数组,数组长度 
*/ 
void insert_sort(int a[],int n){
	int i,j,k;
	for( i=1;i<n;i++){
		k=a[i];
		for( j=i-1;j>=0 && a[j]>k;j--){   //这里采用顺序查找,其实用二分查找更快 
			a[j+1] = a[j];
		}  //出循环时 a[j]<=k 或者 j=-1(k应该放在第一位) 
		a[j+1] = k;  //循环最后一次多减了一次 
	} 
} 

int main(void)
{
	int a[] = {3,2,23,13,23,43,43,4,35,4};
	insert_sort(a,10);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

