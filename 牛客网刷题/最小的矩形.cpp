#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/2b48f56275c64de888c321aeb3492be9
来源：牛客网

牛牛在二维坐标系中画了N个点，且都是整点。现在牛牛想画出一个矩形，使得这N个点都在矩形内或者在矩形上。
矩形的边均平行于坐标轴。牛牛希望矩形的面积最小。请你帮助牛牛计算下最小矩形的面积。 
输入描述:

首先输入一个正整数N表示点的个数（2 <= N <= 50）
  
接下来N行每行两个整数x, y，表示该点的坐标。绝对值均小于等于100.


输出描述:

一个整数表示最小矩形的面积。
示例1
输入

2
0 1
1 0
输出
*/

void minOrMax(int a[],int &min,int &max,int length){
    max=min=a[0];
    for(int i=0;i<length;i++){
        if(a[i]<min){
            min = a[i];
        }
        if(a[i]>max){
            max = a[i];
        }
    }
}

int main(int argc, char** argv) {
    int n;
    cin>>n;
    int x[n];
    int y[n];
    
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    
    int xMin,xMax,yMin,yMax;
    minOrMax(x,xMin,xMax,n);
    minOrMax(y,yMin,yMax,n);
    
    int result = abs(xMin-xMax) * abs(yMin-yMax);
    cout<<result;
    return 0;
}

