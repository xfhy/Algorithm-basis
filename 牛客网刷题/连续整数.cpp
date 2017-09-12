

#include <cstdlib>
#include <iostream>

using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/c3083cd30d5043e1b95000f139b5b2c9
来源：牛客网

牛牛的好朋友羊羊在纸上写了n+1个整数，羊羊接着抹除掉了一个整数，给牛牛猜他抹除掉的数字是什么。牛牛知道羊羊写的整数神排序之后是一串连续的正整数，牛牛现在要猜出所有可能是抹除掉的整数。例如：
10 7 12 8 11 那么抹除掉的整数只可能是9
5 6 7 8 那么抹除掉的整数可能是4也可能是9

输入描述:

输入包括2行：
 第一行为整数n(1 <= n <= 50)，即抹除一个数之后剩下的数字个数
 第二行为n个整数num[i] (1 <= num[i] <= 1000000000)


输出描述:

在一行中输出所有可能是抹除掉的数,从小到大输出,用空格分割,行末无空格。如果没有可能的数，则输出mistake
示例1
输入

2 3 6
输出

mistake

 * 求出最小和最大值min maxNum
 * 求出min-max连续整数的和correctSum
 * 求出给出数组的和sum
 * 求出correctSum-sum  >=maxNum 则 mistake    <maxNum  则输出       相等 则min-1,或者max+1

 */
long int num[51];
int n;
long int minNum=0,maxNum=0;
long int sum=0,correctSum=0;
long int diff;

void getMinAndMax(){
    minNum = num[0];
    maxNum = num[0];
    for(int i=0;i<n;i++){
        if(num[i]<minNum){
            minNum = num[i];
        }
        if(num[i]>maxNum){
            maxNum = num[i];
        }
        sum += num[i];
    }
}

void getCorrectSum(){
    for(long i=minNum; i<=maxNum; i++){
        correctSum += i;
    }
}


int main(int argc, char** argv) {
    
    
    int index=0;
    cin>>n;
    while(index<n){
        cin>>num[index];
        index++;
    }
    
    getMinAndMax();
    getCorrectSum();
    diff = correctSum-sum;
    
    if(diff>=maxNum){
        cout<<"mistake";
    } else if(diff==0){
        if(minNum==1){
            cout<<(maxNum+1);
        } else {
             cout<<(minNum-1)<<" "<<(maxNum+1);
        }
       
    } else {
        cout<<diff;
    }
    
    return 0;
}

