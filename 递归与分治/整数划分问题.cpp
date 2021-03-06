# include <iostream>

using namespace std;

/*
2016年9月18日19:05:32
@XFHY
整数划分问题

整数划分问题是算法中的一个经典命题之一，有关这个问题的讲述在讲解到递归时基本都将涉及。
所谓整数划分，是指把一个正整数n写成如下形式：
n=m1+m2+...+mi; （其中mi为正整数，并且1 <= mi <= n），则{m1,m2,...,mi}为n的一个划分。
如果{m1,m2,...,mi}中的最大值不超过m，即max(m1,m2,...,mi)<=m，则称它属于n的一个m划分。这里我们记n的m划分的个数为f(n,m);
例如但n=4时，他有5个划分，{4},{3,1},{2,2},{2,1,1},{1,1,1,1};
注意4=1+3 和 4=3+1被认为是同一个划分。
该问题是求出n的所有划分个数，即f(n, n)。下面我们考虑求f(n,m)的方法;
1.递归法：
根据n和m的关系，考虑以下几种情况：
(1)当n=1时，不论m的值为多少（m>0)，只有一种划分即{1};
(2)当m=1时，不论n的值为多少，只有一种划分即n个1，{1,1,1,...,1};
(3)当n=m时，根据划分中是否包含n，可以分为两种情况：
(a)划分中包含n的情况，只有一个即{n}；
(b)划分中不包含n的情况，这时划分中最大的数字也一定比n小，即n的所有(n-1)划分。
因此 f(n,n) =1 + f(n,n-1);
(4)当n<m时，由于划分中不可能出现负数，因此就相当于f(n,n);
(5)但n>m时，根据划分中是否包含最大值m，可以分为两种情况：
(a)划分中包含m的情况，即{m, {x1,x2,...xi}}, 其中{x1,x2,... xi} 的和为n-m，因此这情况下
为f(n-m,m)
(b)划分中不包含m的情况，则划分中所有值都比m小，即n的(m-1)划分，个数为f(n,m-1);
因此 f(n, m) = f(n-m, m)+f(n,m-1);
综上所述：
f(n, m)=   1;              (n=1 or m=1)

f(n,m)   =    f(n, n);                   (n<m)

1+ f(n, m-1);              (n=m)

f(n-m,m)+f(n,m-1);         (n>m)
*/

int equationCount(int n,int m){
	if(n<1 || m<1){
		return 0;
	}
	if( (n==1) || (m==1) ){
	    return 1;
	}
	if(n<m){
		return equationCount(n,n);
	}
	if(n==m){
		return 1+equationCount(n,m-1);
	}
	//划分中不包含m的情况，则划分中所有值都比m小，即n的(m-1)划分，个数为f(n,m-1);
	return equationCount(n-m,m)+equationCount(n,m-1); 
}

int main(void){
	int count = equationCount(6,6);
	cout<<count<<endl;
	system("pause");
	return 0;
}