# include <iostream>

using namespace std;

/*
2017年9月28日16:24:08
链接：https://www.nowcoder.com/questionTerminal/f3aaf8fedcea43c6b12a11710068726b
来源：牛客网

度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？ 
输入描述:

首先输入一个正整数N（N <= 50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）


输出描述:

如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1
示例1
输入

10
10 10 10 10 20 20 30 30 40 40
输出

30 
*/ 

//找到比min大一点的那个数 
int find(int a[],int min,int length){
	if(min == -1){
		return -1;
	}
	
	int minTemp = 2147483647; 
	for(int i=0;i<length;i++){
		if(a[i]<minTemp && a[i]>min){
			minTemp = a[i];
		}
	}
	
	if(minTemp==2147483647){
		return -1;
	} else {
		return minTemp;
	}
	
} 

int main(void)
{
	int n;
	cin>>n;
	int a[51];
	int min = 2147483647;  //最小的 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<min){
			min = a[i];
		}
	}
	
	//小于3个输出-1 
	if(n<3){
		cout<<-1;
		return 0;
	}
	
	//找到第二便宜的 
	int second = find(a,min,n);
	//找到第三便宜的 
	int thrid = find(a,second,n);
	
	cout<<thrid;
	
	return 0;
}

