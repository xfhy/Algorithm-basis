#include <iostream>
#include <cstdlib>

using namespace std;

/*
 链接：https://www.nowcoder.com/questionTerminal/df51567da86c456bb962ad58d91804ca
来源：牛客网

小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
小易的老师给了小易这样一个集合：
S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
需要根据给定的w，x，y，z,求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。 
输入描述:

输入包括一行： 一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔


输出描述:

输出集合中元素的个数
示例1
输入

1 10 1 1
输出

10
 * 
 * 思路:其实就是判断分数的值是否相等
 * 
 */

bool isExist(double a[],double temp,int length){
    for(int i=1;i<=length;i++){
        if(temp==a[i]){
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    
    int w,x,y,z;
    cin>>w>>x>>y>>z;
    
    double a[10001];
    int length = 1;
    
    for(int i=w;i<=x;i++){
        for(int j=y;j<=z;j++){
            double temp = i*1.00000/j;
            if(!isExist(a,temp,length)){
                a[length++] = temp;
            }
        }
    }

    cout<<length-1;
    return 0; 

}

