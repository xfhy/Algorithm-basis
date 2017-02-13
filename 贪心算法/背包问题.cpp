#include <iostream>

using namespace std;

/*
2016��11��3��9:55:27 
�������� 
����n����Ʒ��һ����������Ʒ i ������Ϊwi ,���ֵΪvi ,����������Ϊc
���װ��Ʒ��ʹ��װ�뱳������Ʒ�ܼ�ֵ���
���Բ����Ʒ 
*/

int M = 50;        //�������� 
float v[] = {60,120,100};    //��Ʒ��ֵ 
float w[] = {10,30,20};    //��Ʒ���� 
int n = 3;    //��Ʒ���� 
float x[3];

//����  ���ռ�ֵ�ܶ� 
void Sort(int n,float v[],float w[])
{
	float tempV,tempW;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(v[i]/w[i] > v[j]/w[j])
			{
				tempV = v[i];
				v[i] = v[j];
				v[j] = tempV;
				
				tempW = w[i];
				w[i] = w[j];
				w[j] = tempW;
			}
		} 
	} 
}

//̰���㷨   ����:����,��������,��ֵ,����,�Ƿ�װ(����,0����1) 
void Knapsack(int n,float M,float v[],float w[],float x[])
{
	Sort(n,v,w);  //���ݼ�ֵ�ܶ�����
	int i;
	for(i = 0; i<n; i++)   //��ʼ��Ϊ0 
	{
		x[i] = 0; 
	}
	float c = M;
	for(i=0; i<n; i++)
	{
		if(w[i]>c)
		{
			break; 
		}
		x[i] = 1;   //��ǰ��Ʒ���뱳�� 
		c -= w[i];  //������װ�������� 
	} 
	
	//������װ�µ�һ������,װ����
	if(i<n) 
	{
		x[i] = c/w[i];    //ֻװ���ⶫ����һ���� 
	}
} 

int main(void)
{
	Knapsack(n,M,v,w,x);
	cout<<"����"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<w[i]<<" "; 
	}
	cout<<endl<<"��ֵ"<<endl; 
	for(int i=0; i<n; i++)
	{
		cout<<v[i]<<" "; 
	}
	cout<<endl<<"x[i]"<<endl;
    for(int i=0; i<n; i++)
	{
		cout<<x[i]<<" "; 
	}
	return 0;
}
