# include <iostream>

using namespace std;

/*
2017��9��28��16:24:08
���ӣ�https://www.nowcoder.com/questionTerminal/f3aaf8fedcea43c6b12a11710068726b
��Դ��ţ����

�ȶ�����ȥ�̳���һ��ñ�ӣ��̳�����N��ñ�ӣ���Щñ�ӵļ۸������ͬ���ȶ�������һ���۸�������˵�ñ�ӣ��ʵ������˵�ñ�Ӽ۸��Ƕ��٣� 
��������:

��������һ��������N��N <= 50��������������N������ʾÿ��ñ�ӵļ۸񣨼۸��������������С�ڵ���1000��


�������:

������ڵ������˵�ñ�ӣ����������۸��Ƕ��٣��������-1
ʾ��1
����

10
10 10 10 10 20 20 30 30 40 40
���

30 
*/ 

//�ҵ���min��һ����Ǹ��� 
int find(int a[],int min,int length){
	if(min == -1){
		return -1;
	}
	
	int minTemp = 2147483647; 
	for(int i=0;i<length;i++){
		if(a[i]<minTemp && a[i]>min){
			minTemp = a[i];
		}
	}
	
	if(minTemp==2147483647){
		return -1;
	} else {
		return minTemp;
	}
	
} 

int main(void)
{
	int n;
	cin>>n;
	int a[51];
	int min = 2147483647;  //��С�� 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<min){
			min = a[i];
		}
	}
	
	//С��3�����-1 
	if(n<3){
		cout<<-1;
		return 0;
	}
	
	//�ҵ��ڶ����˵� 
	int second = find(a,min,n);
	//�ҵ��������˵� 
	int thrid = find(a,second,n);
	
	cout<<thrid;
	
	return 0;
}

