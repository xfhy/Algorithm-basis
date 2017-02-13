#include <iostream>

using namespace std;

/*
2016��11��4��12:37:33
������������ 

Description 
һ�����������ͺ����ʻn�����;�������ɸ�����վ�����һ����Ч�㷨��
ָ��Ӧ����Щ����վͣ�����ͣ�ʹ��;���ʹ������١���֤���㷨�ܲ���һ�����Ž⡣ 
������� 
���ڸ�����n��k������վλ�ã���̼������ټ��ʹ�����
Input 
�����ɶ������������ɡ� 
ÿ�������������ĵ�һ����2 ��������n��k����ʾ���������ͺ����ʻn���
����;����k������վ����������1 ���У���k+1 ����������ʾ��k������վ���k-1
 ������վ֮��ľ��롣��0 ������վ��ʾ�����أ������Ѽ����͡�
 ��k+1 ������վ��ʾĿ�ĵء�
Output 
��Ӧÿ�����룬�����ÿ���Ǽ���������ټ��ʹ���������޷�����Ŀ�ĵأ�
�������No Solution����
Sample Input 
7 7
1 2 3 4 5 1 6 6
Sample Output 
4
*/
 
int n=7;   //��������������ʻnkm
int k=7;   //����վ ����k�� 


//���ټ��ʹ��� 
int least(int n,int k,int distance[])
{
	int over = 7;   //�����л�ʣ����
	int count=0;
	for(int i=0; i<n; i++){
		//1 2 3 4 5 1 6 6
		if(over > distance[i] && (over-distance[i])>distance[i+1]){
			over -= distance[i];
		} else {
			over = 7;
			count++;
		}
	}	
	return count;
} 

int main(void)
{
	int distance[] = {1,2,3,4,5,1,6,6}; 
	cout<<"�ܹ����ʹ���"<<least(n,k,distance)<<endl; 
	return 0;
}