#include <iostream>
#include <cstdlib>

using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/79ed2f61eef7448aab10ef9677382e7e
来源：牛客网

小易有一块n*n的棋盘，棋盘的每一个格子都为黑色或者白色，小易现在要用他喜欢的红色去涂画棋盘。小易会找出棋盘中某一列中拥有相同颜色的最大的区域去涂画，帮助小易算算他会涂画多少个棋格。 
输入描述:

输入数据包括n+1行：
 第一行为一个整数n(1 ≤ n ≤ 50),即棋盘的大小
 接下来的n行每行一个字符串表示第i行棋盘的颜色，'W'表示白色，'B'表示黑色


输出描述:

输出小易会涂画的区域大小
示例1
输入

3 BWW BBB BWB
输出

3


思路:循环遍历每一列  哪一列的那个字符连续出现的次数最多,则就是答案了 
*/

int main(int argc, char** argv) {
    int n;
    cin>>n;
    char a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    int max = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        char last = a[0][i];
        for(int j=1;j<n;j++){
            if(a[j][i]==last){
            	if(temp==0){
					temp = 2;
				} else {
					temp++;
				}
            } else {
				temp = 0;
			}
            if(temp>max){
                max = temp;
            }
            last = a[j][i];
        }
    }
    
    cout<<max;
    
    return 0;
}


