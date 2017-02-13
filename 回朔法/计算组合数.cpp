# include <iostream>

using namespace std;

/*
2016��11��25��16:45:07
���������
�ҳ�m����Ȼ��(1,2,3,��,m)��n��������ϡ�
Ҫ��    
���룺m,n��5  3
�����
123
124
125
134
135
145
234
235
245
345
��10��


�裨x1,x2,  ����,xn��һ���
Լ��������
��Լ����1��xi��m
��Լ����x1��x2�� ������xn
			        i�� xi ��m��n��i 
���� xi-1 �� xi ��m��n��i 

*/
int m,n;      //�ܹ�m����,n����
int *x;       //һ�����
int count=0;  //���и���
int i;  //�±�

//���һ�����
void output()
{
	count++;
	cout<<endl;
	for(int i=1; i<=n; i++){
		cout<<" "<<x[i];
	}
}

//��˷��
void backtrack(int i){
	if (i>n) output();   //i>n   �����
	else
		for (int j=x[i-1]+1;j<=m-n+i;j++)   //��x[i-1]+1��ʼ
		{
			x[i]=j;   //���Լ�����һ������
			backtrack(i+1);   //+1  ��˷
		} 
}

int main(void)
{
	cout<<endl<<"Please input m,n(m>0) &&(n>0) &&(m>=n))"<<endl;
	do {
		cin>>m>>n;
	}while (!((m>0) &&(n>0) &&(m>=n)));
	x=new int [n+1];
	x[0]=0;
	count=0;
	backtrack(1);
	cout<<endl<<"Total:"<<count<<endl;
	system("pause");
	return 0;
}