# include <iostream>

using namespace std;

/*
2016��11��25��21:42:21
ͼ��m��ɫ����

��Ҫ���ڽӾ���

������
��������(x1, x2, �� , xn)
Լ������
��Լ����1��xi��m
��Լ��������i������ɫ�����ڶ���k����ɫ���ظ�
                         !  (  (a[k][i]==1) && (x[k]==x[i]) )
�㷨���
���ݷ�

������ʾ�������ɰ�
*/

int a[7][7] = {
	{0,1,0,0,1,0,1},
	{1,0,0,1,0,1,0},
	{0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,0,0,0,0,1},
	{0,1,0,1,0,0,0},
	{1,0,1,1,1,0,0}
};
int *x;    //������
int count=0;
int n=7,m=3;

//���   ���ڵ������Ƿ�����ͬ����ɫ
bool check(int i)
{
	for(int k=1; k<i; k++)
	{
		if( (a[k][i]==1) && (x[k]==x[i]) )   //�Ƿ�����           ��ɫ�Ƿ���ͬ     
		{
			return false;
		}
	}
	return true;
}

//���һ�����
void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
}

//������ɫ
void trycolor(int i)
{
	if(i>n)
		output();
	else
	{
		for(int j=1; j<=m; j++)
		{
			x[i] = j;    //������ɫ
			if(check(i))  //���
				trycolor(i+1);
		}
	}
}

int main(void)
{
	x = new int[n+1];
	count=0;
	trycolor(1);
    cout<<endl<<"Total:"<<count<<endl;
	system("pause");
	return 0;
}