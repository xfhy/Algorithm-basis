#include <iostream>

using namespace std;
 
/*
2016��11��11��12:19:21 
��������
����ҳ�m����Ȼ��(1,2,3,��,m)��n�������������С�
����
��������(x1,x2,  ����,xn��
Լ��������
��Լ����1��xi��m
��Լ����xi  �� xj      ( 1��i��j��n   )
*/

//class My{
//public:
//   static int count;
//};
//int My::count=20;

//int m = 5;
//int n = 3;
//int *x;
//int count = 0;

//void backtrack(int i);
//void output();
//bool check1(int i);
//
//void backtrack(int i)
//{
//	if(i > n)
//	{
//		output();
//	} 
//	else 
//	{
//		for(int j=1; j <= m; j++){
//			x[i] = j;   //����ǰ����ֵ��x[i] 
//			if(check1(i))   //�ж�֮ǰ�Ƿ���ֹ� 
//			{
//				backtrack(i+1);  //���� 
//			}
//		}
//	}
//	
//}
//
//�������
//void output()
//{
//	count++;
//	cout<<endl;
//	for(int i=1; i<=n; i++){
//		cout<<" "<<x[i];
//	}
//} 
//
////���֮ǰ���Ƿ���,�����򷵻�false
//bool check1(int i){
//	for (int k=1;k<i;k++)
//		if (x[k]==x[i]) return false;
//	return true;
//}
//
//int main(void)
//{
//	x=new int [n+1];
//	x[0]=0;
//	backtrack(1);
//	cout<<endl<<"Total:"<<count<<endl;
//	system("pause");
//	return 0;
//}

/*------------------------------������Ϊ��������Щ��,�Ҳ��ǵݹ��-------------------------------*/
int m,n;
int *x;       //��������������
int count=0;  //���и���
int i;  //�±�
bool ok = true;

//�ж�֮ǰ�Ƿ��Ѿ�����
bool check(int i)
{
	for(int k=1; k<i; k++)
	{
		if(x[k]==x[i]) 
			return false;
	}
	return true;
}

void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
} 

//����
void change()
{
	//����
	while(x[i]==m)
	{
		i--;
	}
	x[i]++;   //�˻ص�����ǰ�����Ǹ���+1
}

//����
void extend()
{
	i++;
	x[i] = 1;  //
}

int main(void)
{
	cin>>m>>n;
	x = new int[n+1];
	count=0;
	i=0;
	x[i]=0;
	ok = true;

	do
	{
		if(ok)
		{
			if(i==n)
			{
				output();
				change();
			} else {
				extend();
			}
		} else {
			change();
		}
		ok = check(i);
	}while(i>0);

	system("pause");
	return 0;
}

