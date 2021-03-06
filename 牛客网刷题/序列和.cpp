
#include <cstdlib>
#include <iostream>

using namespace std;

/*

链接：https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9
来源：牛客网

给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
例如 N = 18 L = 2：
5 + 6 + 7 = 18 
3 + 4 + 5 + 6 = 18
都是满足要求的，但是我们输出更短的 5 6 7

输入描述:

输入数据包括一行： 两个正整数N(1 ≤ N ≤ 1000000000),L(2 ≤ L ≤ 100)


输出描述:

从小到大输出这段连续非负整数，以空格分隔，行末无空格。如果没有这样的序列或者找出的序列长度大于100，则输出No
示例1
输入

18 2
输出

5 6 7
*/

int main(int argc, char** argv) {
    
    long int N,L;
    cin>>N>>L;
    long int sum = 0;
    for(int i=L;i<=100;i++){
        //可以除清楚,那么这一项成立An   即可以实现等差数列和为N   这里的i代表等差数列有多少项
        if ( (2*N+i-i*i)%(2*i)==0 ) {
            int start = (2*N+i-i*i)/(2*i);  //a1
            for(int j=0;j<i;j++){
                if(j==i-1){
                    cout<<start+j;
                } else {
                    cout<<start+j<<" "; 
                }
                
            }
            return 0;
        }
    }
    
    cout<<"No";
    return 0;
}

