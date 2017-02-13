#include <iostream>
#include <malloc.h>

using namespace std;

/*
2016年9月23日13:41:39
最大子段和 

问题： 给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n],
求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。
当所给的整均为负数时定义子段和为0，依此定义，所求的最优值为：
 Max{0,a[i]+a[i+1]+…+a[j]},1<=i<=j<=n 例如，
 当（a[1],a[2],a[3],a[4],a[5],a[6]）=(-2,11,-4,13,-5,-2)时，
 最大子段和为20。
*/


//int a[20] =  {1,-213,233,434,213,414,131,131,32,23,435,
//45,65,34,56,7,2,234,-2,12};  //正确结果是 2~19 = 2499 

int a[6] = {-2,11,-4,13,-5,-2};

/*
这是一种简单的算法,也是比较容易想到的一种算法. 
0 <= i <= j <= n
2重循环,i从0开始,j从i开始,不断的计算从j到某个结点之间和的最大值
如果遇到和最大的,则立刻保存结果,也将下标(besti~bestj)也保存下来. 
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
分治算法    
最开始时将整个数组分为 2半,但是后来发现不行,因为还有1种情况,有可能最大字段和
的besti在左半边,bestj在右半边.所有需要新增中间那个.需要将数组分为3份 
*/
int MaxSubSum(int *a,int left,int right){
	int sum=0;
	if(left == right){  //出口    判断左边下标是否与右边下标相等 
		sum =  a[left] > 0 ? a[left]:0;
	} else {
		
		//规模减半 
		int center = (left+right)/2;   //中间位置下标 ,二分 
		int leftsum = MaxSubSum(a,left,center);  //左边最大子段和 
		int rightsum = MaxSubSum(a,center+1,right); //右边最大子段和
		
		//中间段的左边部分,循环从center往左加,找左半段的最大子段和 
		int s1 = 0;
		int lefts = 0;
		for(int i=center; i>=left; i--){
			lefts += a[i];
			if(lefts > s1){
				s1 = lefts;
			}
		} 
		
		//中间段的右边部分,循环从center+1往右加,找右半段的最大字段和
		int s2 = 0;
		int rights = 0;
		for(int i=center+1; i<= right; i++){
			rights += a[i];
			if(rights > s2){
				s2 = rights;
			}
		} 
		
		//中间段的总和 
		sum = s1+s2;  
		
		//左边,右边,中间段最大子段和进行比较,谁最大 
		if(sum < leftsum) sum = leftsum;
		if(sum < rightsum) sum = rightsum; 
	} 
	return sum;
}

//动态规划法 
int max_sum(int n,int *a,int &besti,int &bestj)
{
    int *b = (int *)malloc(n * sizeof(int));
    int sum = 0;
    int i = -1;
    int temp = 0;

    for (i=0;i<=n-1;i++) {   //求出到a[i]的最大字段和 
        if (temp > 0) 
            temp += a[i];
        else
            temp = a[i];
        b[i] = temp;
    }

    sum = b[0];
    for (i=1;i<=n-1;i++) {   //找出字段和的最大值  并记录当前下标 (尾部)
        if (sum < b[i]) {
            sum = b[i];
            bestj = i;
        }
    } 

    for (i = bestj;i >= 0;i--) {  //找出头部   即开始记录的下标 
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
