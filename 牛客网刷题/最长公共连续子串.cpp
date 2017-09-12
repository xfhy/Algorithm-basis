#include <cstdlib>
#include <iostream>

using namespace std;

/*

链接：https://www.nowcoder.com/questionTerminal/276712b113c6456c8cf31c5073a4f9d7
来源：牛客网

牛牛有两个字符串（可能包含空格）,牛牛想找出其中最长的公共连续子串,希望你能帮助他,并输出其长度。 
输入描述:

输入为两行字符串（可能包含空格），长度均小于等于50.


输出描述:

输出为一个整数，表示最长公共连续子串的长度。
示例1
输入

abcde
abgde
输出

2
*/
int main(int argc, char** argv) {

    int maxI=0,maxJ=0;  //最长时的 行,列坐标
    int maxL = 0;  //最长长度
    char a[51];
    char b[51];
    int c[51][51] = {0};
    cin.getline(a,50);
    cin.getline(b,50);
    
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            if(b[j]=='\0'){
                break;
            }
            if(a[i]==b[j]){
                if(i==0 || j==0){
                    c[i][j]=1;
                } else {
                    c[i][j] = c[i-1][j-1]+1; 
                }
                if(c[i][j]>maxL){
                    maxL = c[i][j];
                    maxI = i;
                    maxJ = j;
                }
            } 
        }
    }
    
    cout<<maxL;
    return 0;
}

