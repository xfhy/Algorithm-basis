#include <iostream>

using namespace std;

/*
2016年11月4日12:37:33
汽车汽油问题 

Description 
一辆汽车加满油后可行驶n公里。旅途中有若干个加油站。设计一个有效算法，
指出应在哪些加油站停靠加油，使沿途加油次数最少。并证明算法能产生一个最优解。 
编程任务： 
对于给定的n和k个加油站位置，编程计算最少加油次数。
Input 
输入由多组测试数据组成。 
每组测试数据输入的第一行有2 个正整数n和k，表示汽车加满油后可行驶n公里，
且旅途中有k个加油站。接下来的1 行中，有k+1 个整数，表示第k个加油站与第k-1
 个加油站之间的距离。第0 个加油站表示出发地，汽车已加满油。
 第k+1 个加油站表示目的地。
Output 
对应每组输入，输出的每行是计算出的最少加油次数。如果无法到达目的地，
则输出”No Solution”。
Sample Input 
7 7
1 2 3 4 5 1 6 6
Sample Output 
4
*/
 
int n=7;   //汽车加满油能行驶nkm
int k=7;   //加油站 个数k个 


//最少加油次数 
int least(int n,int k,int distance[])
{
	int over = 7;   //油箱中还剩多少
	int count=0;
	for(int i=0; i<n; i++){
		//1 2 3 4 5 1 6 6
		if(over > distance[i] && (over-distance[i])>distance[i+1]){
			over -= distance[i];
		} else {
			over = 7;
			count++;
		}
	}	
	return count;
} 

int main(void)
{
	int distance[] = {1,2,3,4,5,1,6,6}; 
	cout<<"总共加油次数"<<least(n,k,distance)<<endl; 
	return 0;
}