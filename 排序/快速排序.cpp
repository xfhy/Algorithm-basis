# include <iostream>
# include <stdlib.h>
# include <time.h>

using namespace std;

/*
2016��10��2��12:29:24
��������
 a.����(O(n^2))   eg:�Ѿ�����
 b.ƽ��(O(nlogn))

����˼��:1���ȴ�������ȡ��һ������Ϊ��׼����
         2���������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
         3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������

��׼����ѡȡ:
 a.��ͳ�ķ���(a[0]) �������
 b.���ѡȡ
 c.��ֵ
*/

void Swap(int &c,int &d);
int Rondom(int p,int r);
int RandomizedPartition(int a[],int p,int r);
int Partition(int a[],int low,int high);
void Sort(int a[],int low,int high);


int a[10] = {31,31,31,2,1,41,41,435,451,51};   //ԭʼ��������

//����2����
void Swap(int &c,int &d)
{
	int temp = c;
	c = d;
	d = temp;
}

//���������
int Rondom(int p,int r)
{
	srand((unsigned)time(NULL));
	return rand()%(r-p)+p;
}

//���ѡ���׼��,���ڸ÷ŵ�λ��,�����ظ���������
int RandomizedPartition(int a[],int p,int r)
{
	int i = Rondom(p,r);
	Swap(a[i],a[p]);   //�������һ������Ϊ��׼��
	return Partition(a,p,r);   //��һ��,�øû�׼�����ں��ʵ�λ��,�����ظ�λ�õ�����
}

//���ѡ��һ����,��Ϊ��׼�Ŀ�������
void RandomSort(int a[],int low,int high)
{
	if(low < high)
	{
		int pivotloc = RandomizedPartition(a,low,high);    //����һ�����ں��ʵ�λ��,��ȡ�������±�
		Sort(a,low,pivotloc-1);       //���η�      �м��Ǹ���(pivotloc)�Ѿ����к���,�Ѿ������˺��ʵ�λ��
		Sort(a,pivotloc+1,high);
	}
}

//���������һ��ѭ��
//�㷨����һ����������С�ķŵ�������ǰ�棬������ķŵ������ĺ���   
//����Ļ�׼�����ͳ��ѡ��,ֱ�ӽ���һ����Ϊ��׼��
int Partition(int a[],int low,int high)
{
	int pivotkey = a[low];   //��׼��
	while(low < high)  //���ٽ�Ԫ�طŵ��ʵ���λ�ã�ǰС���
	{
		while(low < high && a[high]>=pivotkey)  //�� ����ǰѭ����������pivotkeyС�ģ��ͰѸ�ֵ�ŵ�ǰ��ȥ
		{
			high--;
		}
		a[low] = a[high];  //�˳�ѭ��ʱ��a[high]<=pivotkey

		while(low < high && a[low]<=pivotkey)
		{
			low++;
		}
		a[high] = a[low];  //�˳�ѭ��ʱ��a[low]>=pivotkey
	}
	a[low] = pivotkey;  //�ع�
	return low;
}

//�����������
void Sort(int a[],int low,int high)
{
	if(low < high)
	{
		int pivotloc = Partition(a,low,high);    //����һ�����ں��ʵ�λ��,��ȡ�������±�
		Sort(a,low,pivotloc-1);       //���η�      �м��Ǹ���(pivotloc)�Ѿ����к���,�Ѿ������˺��ʵ�λ��
		Sort(a,pivotloc+1,high);
	}
}

/*
����ѡ���㷨
    ѡ�����ⶨ�壬ʵ�������д���������ƹ㵽�����а����ظ���ֵ�����Ρ�
    ���룺һ������n������ͬ�ģ����ļ���A��һ����i��1<=i<=n��
    �����Ԫ��x����A����ǡ����A��������i-1��Ԫ�ء�
*/

int main(void)
{
	//Sort(a,0,9);   //��ͳ�Ŀ�������
	RandomSort(a,0,9);  //���ѡ���׼���Ŀ�������(����������)

	//�������
	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" ";
	}

	system("pause");
	return 0;
}