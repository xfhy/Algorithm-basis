#include <iostream>
#define N 6     //��Ʒ��Ŀ 
#define W 10    //���������� 

/*
2016��10��21��18:14:42
0-1�������� 
*/
using namespace std;

int B[N][W] = {0};
//int w[6] = {0,2,3,4,5,9};
//int V[6] = {0,3,4,5,8,10};
int w[6] = {0,2,2,6,5,4};
int V[6] = {0,6,3,5,4,6};

void knapsack(){
   int k,c;  
   for(k=1; k<N; k++){
   	  for(c=1; c<W; c++){   
      	if(w[k] > c){   //�������̫����,��Ҫ 
			  B[k][c] = B[k-1][c];  //��ʣ�µĶ�����ѡ 
	    } else {  //���Է���,  ��ѡ����,���߲��� 
	    	//�����.�򱳰�����-w[k],���Ӽ�ֵv[k] 
			int value1 = B[k-1][c-w[k]] + V[k];
			//�������,����ʣ�µĶ�������   ��� 
			int value2 = B[k-1][c];
			if(value1>value2){
				B[k][c] =  value1;
			} else {
				B[k][c] = value2;
			}
		}
	  }
   }
}

int main(void)
{
	knapsack();
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<W; j++)
		{
			cout<<B[i][j]<<"  ";
		}
		cout<<endl; 
	}
	//cout<<B[5][20]<<endl;      //���½��Ǹ����� 
	return 0;
}
