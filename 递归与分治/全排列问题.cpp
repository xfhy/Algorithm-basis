# include <iostream>

using namespace std;

/*
2016��9��18��9:59:35
����1������,����������е�ȫ���� 
*/

inline void Swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

//��pszStr�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������  
bool IsSwap(int list[], int nBegin, int nEnd)  
{  
    for (int i = nBegin; i < nEnd; i++)  
        if (list[i] == list[nEnd])  
            return false;  
    return true;  
}  

void Perm(int list[],int k,int m){
	//����list[k:m]����������
	if(k == m){   //���������� 
		//ֻʣ��1��Ԫ��
		for(int i=0; i<=m; i++){
			cout<<list[i];
		} 
		cout<<endl;
	} else {
		for(int i=k; i<=m; i++){
			//Ϊ�����ظ� 
			if(IsSwap(list,k,i))
			{
				Swap(list[k],list[i]); 
				Perm(list,k+1,m); 
				Swap(list[k],list[i]); //�ָ��ֳ� 
			}
			
		}
	}
}

int main(void){
	int list[5] = {1,1,2,2,5}; 
	Perm(list,0,4);
    return 0;
}

