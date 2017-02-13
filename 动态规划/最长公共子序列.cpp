#include <iostream>

using namespace std;

/*
2016��10��23��12:22:44
����������� 
ʲô�������������(���Բ���������)�أ��ٸ��򵥵����Ӱɣ�һ������S��
���ֱ�������������֪���е������У��������з���������������ģ�
��S��Ϊ��֪���е�����������С�

  �������£��磺������������У�1 2 3 4 5 6 �� 3 4 5 8 9��
  �����ǵ�����������б��ǣ�3 4 5��
*/

int **c = NULL;   //c[m][n]������������еĳ���
char **b = NULL;   //��ά����  ȫ�ֵ�
int row=3;   //��
int col=4;   //��
char x[] = {'B','C','B','D','F'};
char y[] = {'A','B','C','B','D','A','B'};

/*
��������������еĶ�̬�滮�㷨
����:
m:A���еĳ���
n:B���еĳ���
x:A����(����)
y:B����(����)
c:c[i][j]:�洢X[i]��Y[j]����������еĳ���
b:b[i][j]:��¼c[i][j]�Ǵ���һ���������˽⵽��(1:���Ͻ��Ǹ�,2:�ϱ��Ǹ�,3:����Ǹ�)
*/
void LCSLength(int m,int n,char *x,char *y,int ** c){
	int i,j;

	//��ʼ��,����һ�е�һ�г�ʼ��Ϊ0(����Ϊ0�������������κ����е������������Ϊ0)
	for(i=0; i<=m; i++){
		c[i][0] = 0;
	}
	for(j=0; j<=n; j++){
		c[0][j] = 0;
	}
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(x[i]==y[j]){   //�����������ַ����ʱ,�򽫳���+1
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			} else if(c[i-1][j]>=c[i][j-1]){  //�ϱߴ������
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
	}
}

/*
��ӡ�����������
*/
void LCS(int i,int j,char *x,char **b){
	if(i==0 || j==0)   //�ݹ����,�������߽�ʱ
		return ;
	if(b[i][j]==1){    //�����1,��˵���Ǵ����Ͻ�������
		LCS(i-1,j-1,x,b);
		cout<<x[i];
	} else if(b[i][j]==2){  //�����2,���Ǵ��ϱ�������
		LCS(i-1,j,x,b);
	} else {
		LCS(i,j-1,x,b);
	}
}

//��̬���ɶ�ά���� 
void makeArray(int row,int col)
{
	b = new char *[row+1];
	c = new int*[row+1];
	for(int i=0; i<row+1; i++){
		b[i] = new char[col+1];
		c[i] = new int[col+1];
	}	
} 

//��ά���� ʹ�ò����
void printCout(int row,int col){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			b[i][j] = i*j;
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl; 
	}
} 

int main(void)
{
	makeArray(row,col);
	LCSLength(row,col,x,y,c);
	LCS(row,col,x,b);
	system("pause");
	return 0;
}
