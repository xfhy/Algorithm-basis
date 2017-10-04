# include <iostream>
#include <cstdlib>
#include<math.h>
# include <map>

using namespace std;
map<int,bool> m;

/*
 链接：https://www.nowcoder.com/questionTerminal/99fa7be28d5f4a9d9aa3c98a6a5b559a
来源：牛客网

给出一个区间[a, b]，计算区间内“神奇数”的个数。
神奇数的定义：存在不同位置的两个数位，组成一个两位数（且不含前导0），且这个两位数为质数。
比如：153，可以使用数字3和数字1组成13，13是质数，满足神奇数。同样153可以找到31和53也为质数，只要找到一个质数即满足神奇数。 
输入描述:

输入为两个整数a和b，代表[a, b]区间 (1 ≤ a ≤ b ≤ 10000)。


输出描述:

输出为一个整数，表示区间内满足条件的整数个数
示例1
输入

11 20
输出

6
 * 
 * 
 * 思路：先把10-99是不是神奇数存下来，免得每次都去计算  
 * 再依次遍历
 */

//判断是否是质数
bool isPrime(int n){
    int k = sqrt(n);
    int i=0;
    for(i=2;i<=k;i++){
        if(n%i==0){
            break;
        }
    }
    return i==(k+1);
}

//判断是否是神奇数
bool isMagicNum(int x){
    int numB[10] = {-1};
    int n=0;
    while(x!=0){
        numB[n++] = x%10;
        x /= 10;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(numB[i]!=0 && m[numB[i]*10+numB[j]]==true){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int min,max;
    cin>>min>>max;
    
    
    for(int i=10;i<100;i++){
        if(isPrime(i)){
            m[i]=true;
        } else {
            m[i]=false;
        }
    }
    
    int count=0;
    for(int i=min;i<=max;i++){
        if(isMagicNum(i)){
            count++;
        } 
    }
    cout<<count;
    return 0;
}

