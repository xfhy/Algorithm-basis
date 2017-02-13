# include <iostream>

using namespace std;

/*
2016年9月18日9:59:35
对于1个数组,输出它的所有的全排列 
*/

inline void Swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

//在pszStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等  
bool IsSwap(int list[], int nBegin, int nEnd)  
{  
    for (int i = nBegin; i < nEnd; i++)  
        if (list[i] == list[nEnd])  
            return false;  
    return true;  
}  

void Perm(int list[],int k,int m){
	//产生list[k:m]的所有排列
	if(k == m){   //输出这个数组 
		//只剩下1个元素
		for(int i=0; i<=m; i++){
			cout<<list[i];
		} 
		cout<<endl;
	} else {
		for(int i=k; i<=m; i++){
			//为避免重复 
			if(IsSwap(list,k,i))
			{
				Swap(list[k],list[i]); 
				Perm(list,k+1,m); 
				Swap(list[k],list[i]); //恢复现场 
			}
			
		}
	}
}

int main(void){
	int list[5] = {1,1,2,2,5}; 
	Perm(list,0,4);
    return 0;
}

