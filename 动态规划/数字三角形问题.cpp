# include <iostream>

using namespace std;

/*

2016��10��9��14:32:00
��������������

����:����һ����n��������ɵ���������������ͼ��ʾ�������һ���㷨��
������������εĶ����׵�һ��·����ʹ��·�������������ܺ����

��������
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

�������
30
*/

const int M=100;
int n;
int a[M][M];
int func()
{
  int i,j;
 for(i=n-1;i>=1;i--)
 {
	  for(j=1;j<=i;j++)
	  {
		   if(a[i+1][j]>a[i+1][j+1])
			   a[i][j]+=a[i+1][j];
		   else 
			   a[i][j]+=a[i+1][j+1]; 
	  }
 }
  return a[1][1];
}

int main(void)
{
	int i,j,max;
    cin>>n;
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
    max=func();
    cout<<max<<endl;
	system("pause");
	return 0;
}