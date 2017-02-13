#include <iostream>
#define N 6     //物品数目 
#define W 10    //背包最大承重 

/*
2016年10月21日18:14:42
0-1背包问题 
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
      	if(w[k] > c){   //这件东西太重了,不要 
			  B[k][c] = B[k-1][c];  //在剩下的东西里选 
	    } else {  //可以放下,  可选择拿,或者不拿 
	    	//如果拿.则背包承重-w[k],增加价值v[k] 
			int value1 = B[k-1][c-w[k]] + V[k];
			//如果不拿,则在剩下的东西里拿   查表 
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
	//cout<<B[5][20]<<endl;      //右下角那个就是 
	return 0;
}
