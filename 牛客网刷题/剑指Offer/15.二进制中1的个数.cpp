#include <iostream>

/*
 * 2017年11月17日18:26:10
 * 面试题15:面试题中1的个数

 举一反三:把一个整数减去1之后再和原来的整数做位与(&)运算,得到的结果相当于把整数的二进制表示中最右边的1变成0.
 eg:1100-1=1011 1100&1011=1000
 * */

using namespace std;

//常规解法
int numberOf1(int n){
    int count=0;
    unsigned int flag = 1;
    while(flag){   //循环次数由整数的二进制位数来控制  32位的整数需要循环32次
        if(n&flag){ //如果&1等于1,那么那一位就是1     则结果+1
            count++;
        }
        flag=flag<<1;
    }
    return count;
}

//能给面试官带来惊喜的算法
int numberOf2(int n) {
    int count = 0;
    while (n) {
        count++;  //只要不为0,那么肯定有一位是1
        n = n & (n - 1);  //1100-1=1011 1100&1011=1000 这样就依次把最后的那个1干掉   直到为0
    }
    return count;
}

int main() {
    cout << numberOf2(0xFFFFFFF);
    return 0;
}