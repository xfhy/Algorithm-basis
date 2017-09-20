#include <cstdlib>
#include <iostream>

using namespace std;

/*
    链接：https://www.nowcoder.com/questionTerminal/a4690c9a420b423db91b1c109c133a52
来源：牛客网

在幼儿园有n个小朋友排列为一个队伍，从左到右一个挨着一个编号为(0~n-1)。其中有一些是男生，有一些是女生，男生用'B'表示，女生用'G'表示。小朋友们都很顽皮，当一个男生挨着的是女生的时候就会发生矛盾。作为幼儿园的老师，你需要让男生挨着女生或者女生挨着男生的情况最少。你只能在原队形上进行调整，每次调整只能让相邻的两个小朋友交换位置，现在需要尽快完成队伍调整，你需要计算出最少需要调整多少次可以让上述情况最少。例如：
GGBBG -> GGBGB -> GGGBB
这样就使之前的两处男女相邻变为一处相邻，需要调整队形2次 
输入描述:

输入数据包括一个长度为n且只包含G和B的字符串.n不超过50.


输出描述:

输出一个整数，表示最少需要的调整队伍的次数
示例1
输入

GGBBG
输出

2
 * 
 * 思路:要么是男生全部站左边,要么是全部女生站左边,现在就统计一下,
 * 
 * 将全部男生站在左边需要移动多少次,比如(GGBBG),则第一个男生需要移动到bIndex=0处,需要移动2次
 * 
 * 最后将男生全部站左边需要移动的次数和女生全部站左边需要移动的次数进行比较,谁小就输出谁
 */
int main(int argc, char** argv) {
    char *stu = new char[51];
    
    cin>>stu;
    int bSum = 0;  //男生需要移动的次数
    int gSum = 0;  //女生需要移动的次数
    int bIndex=0;  //第0个是男生   记录每次将男生移动到左边的位置
    int gIndex = 0; //第0个是女生
    
    if(stu==NULL){
        cout<<-1;
        return 0;
    }
    
    char c = stu[0];
    for(int i=0;c!='\0';i++){
        c = stu[i];
        if(c=='\0'){
            break;
        }else if(c=='B'){  //将男生全部移动到左边
            bSum = bSum + i- bIndex;
            bIndex++;
        }else if(c=='G'){  //将全部女生移动到左边
            gSum += i - gIndex;
            gIndex++;
        }
    }
    
    if(bSum>gSum){
        cout<<gSum;
    } else {
        cout<<bSum;
    }
    
    return 0;
}

