#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * 2017年10月05日17:08:14
 链接：https://www.nowcoder.com/questionTerminal/b2b816e20e8343b49abbaf493886ce26
来源：牛客网

牛牛手里有一个字符串A，羊羊的手里有一个字符串B，B的长度大于等于A，所以牛牛想把A串变得和B串一样长，这样羊羊就愿意和牛牛一起玩了。
而且A的长度增加到和B串一样长的时候，对应的每一位相等的越多，羊羊就越喜欢。比如"abc"和"abd"对应相等的位数为2，为前两位。
牛牛可以在A的开头或者结尾添加任意字符，使得长度和B一样。现在问牛牛对A串添加完字符之后，不相等的位数最少有多少位？ 
输入描述:

第一行为字符串A，第二行为字符串B，A的场地小于等于B的长度，B的长度小于等于50.字符均为小写字母。


输出描述:

输出一个整数表示A串添加完字符之后，不相等的位数最少有多少位？
示例1
输入

abe
cabc
输出

1
 */

int main(int argc, char** argv) {
    
    //char a[51],b[51];
    string a,b;
    getline(cin,a);  //输入一行字符串  空格也不算在里面
    getline(cin,b);
    
    int aSize = a.size();
    int bSize = b.size();
    int count=0,max=0,lineCount=0;
    
    //求出最大的相同的字符个数
    for(int j=0;j<bSize;j++){
        for(int i=0;i<aSize;i++){
            if(b[j+i]==a[i]){
                lineCount++;
            }
        }
        if(lineCount>max){
            max = lineCount;
        }
        if(aSize==bSize){  //字符串长度一样则不用比较了
            cout<<aSize-max;
            return 0;
        }
        lineCount = 0;
    }
    
    cout<<bSize-max-(bSize-aSize);
    
    return 0;
}

