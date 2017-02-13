#include <iostream>
#include <malloc.h>

using namespace std;

/*
2016��9��23��13:41:39
����Ӷκ� 

���⣺ ����n������������Ϊ��������ɵ�����a[1],a[2],a[3],��,a[n],
���������a[i]+a[i+1]+��+a[j]���Ӷκ͵����ֵ��
������������Ϊ����ʱ�����Ӷκ�Ϊ0�����˶��壬���������ֵΪ��
 Max{0,a[i]+a[i+1]+��+a[j]},1<=i<=j<=n ���磬
 ����a[1],a[2],a[3],a[4],a[5],a[6]��=(-2,11,-4,13,-5,-2)ʱ��
 ����Ӷκ�Ϊ20��
*/


//int a[20] =  {1,-213,233,434,213,414,131,131,32,23,435,
//45,65,34,56,7,2,234,-2,12};  //��ȷ����� 2~19 = 2499 

int a[6] = {-2,11,-4,13,-5,-2};

/*
����һ�ּ򵥵��㷨,Ҳ�ǱȽ������뵽��һ���㷨. 
0 <= i <= j <= n
2��ѭ��,i��0��ʼ,j��i��ʼ,���ϵļ����j��ĳ�����֮��͵����ֵ
�������������,�����̱�����,Ҳ���±�(besti~bestj)Ҳ��������. 
*/
int MaxSum1(int n,int *a,int& besti,int& bestj){
	int sum = 0;
	int thissum = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			thissum += a[j];
			if(thissum > sum){
				sum = thissum;
				besti = i;
				bestj = j;
			}
		}
		thissum = 0;
	} 
	return sum;
}

/*
�����㷨    
�ʼʱ�����������Ϊ 2��,���Ǻ������ֲ���,��Ϊ����1�����,�п�������ֶκ�
��besti������,bestj���Ұ��.������Ҫ�����м��Ǹ�.��Ҫ�������Ϊ3�� 
*/
int MaxSubSum(int *a,int left,int right){
	int sum=0;
	if(left == right){  //����    �ж�����±��Ƿ����ұ��±���� 
		sum =  a[left] > 0 ? a[left]:0;
	} else {
		
		//��ģ���� 
		int center = (left+right)/2;   //�м�λ���±� ,���� 
		int leftsum = MaxSubSum(a,left,center);  //�������Ӷκ� 
		int rightsum = MaxSubSum(a,center+1,right); //�ұ�����Ӷκ�
		
		//�м�ε���߲���,ѭ����center�����,�����ε�����Ӷκ� 
		int s1 = 0;
		int lefts = 0;
		for(int i=center; i>=left; i--){
			lefts += a[i];
			if(lefts > s1){
				s1 = lefts;
			}
		} 
		
		//�м�ε��ұ߲���,ѭ����center+1���Ҽ�,���Ұ�ε�����ֶκ�
		int s2 = 0;
		int rights = 0;
		for(int i=center+1; i<= right; i++){
			rights += a[i];
			if(rights > s2){
				s2 = rights;
			}
		} 
		
		//�м�ε��ܺ� 
		sum = s1+s2;  
		
		//���,�ұ�,�м������Ӷκͽ��бȽ�,˭��� 
		if(sum < leftsum) sum = leftsum;
		if(sum < rightsum) sum = rightsum; 
	} 
	return sum;
}

//��̬�滮�� 
int max_sum(int n,int *a,int &besti,int &bestj)
{
    int *b = (int *)malloc(n * sizeof(int));
    int sum = 0;
    int i = -1;
    int temp = 0;

    for (i=0;i<=n-1;i++) {   //�����a[i]������ֶκ� 
        if (temp > 0) 
            temp += a[i];
        else
            temp = a[i];
        b[i] = temp;
    }

    sum = b[0];
    for (i=1;i<=n-1;i++) {   //�ҳ��ֶκ͵����ֵ  ����¼��ǰ�±� (β��)
        if (sum < b[i]) {
            sum = b[i];
            bestj = i;
        }
    } 

    for (i = bestj;i >= 0;i--) {  //�ҳ�ͷ��   ����ʼ��¼���±� 
        if (b[i] == a[i]) {
            besti = i;
            break;
        }
    }
        
    free(b);
    return sum; 
}


int main(void)
{
	int besti=0,bestj=0,n=20;
	//int result = MaxSum1(n,a,besti,bestj);
	//int result = MaxSubSum(a,0,5);
	int result = max_sum(5,a,besti,bestj); 
	if(result<0){
		printf("0 \n");
	} else {
		printf("%d ~ %d = %d \n",besti,bestj,result);
	}
	return 0;
}
