# include <iostream>

using namespace std;

/**
description �������� 
author xfhy
create at
*/

/**
�������� 
����:����������,���鳤�� 
*/ 
void insert_sort(int a[],int n){
	int i,j,k;
	for( i=1;i<n;i++){
		k=a[i];
		for( j=i-1;j>=0 && a[j]>k;j--){   //�������˳�����,��ʵ�ö��ֲ��Ҹ��� 
			a[j+1] = a[j];
		}  //��ѭ��ʱ a[j]<=k ���� j=-1(kӦ�÷��ڵ�һλ) 
		a[j+1] = k;  //ѭ�����һ�ζ����һ�� 
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

