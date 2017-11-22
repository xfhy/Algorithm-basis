#include <iostream>
#include <cstring>

/*
 * 2017年11月22日18:24:24
 * 面试题17: 打印从1到最大的n位数

 注意:n可能是一个超级大数(long long都会溢出的那种大)
 * */

using namespace std;

/*-------------------------方式1----------------------------*/

bool Increment(char *number) {
    bool isOverflow = false; //是否溢出  溢出则不用再+1了
    int nTakeOver = 0;  //进位
    int nLength = strlen(number);  //字符串的长度
    for (int i = nLength - 1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeOver;  //倒数第i位+进位
        if (i == nLength - 1) {  //只需要最后一位+1
            nSum++;
        }
        if (nSum >= 10) { //如果需要进位
            if (i == 0) {  //第一位溢出
                isOverflow = true;
            } else { //第一位没有溢出   则加上nSum
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {   //小于10  则不需要继续加+1了
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

//打印
void PrintNumber(char *number) {
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for (int i = 0; i < nLength; i++) {
        //判断是否前面的是0
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            cout << number[i];
        }
    }
    cout << endl;
}

void Print1ToMaxOfNDigits(int n) {
    if (n <= 0) {
        return;
    }
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number)) {  //+1
        PrintNumber(number);  //打印
    }
}

/*--------------------------方式2-------------------------*/

//递归打印
void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index) {
    if (index == length - 1) {  //如果已经是最后一位,那么直接打印,并结束这个递归
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0'; //排列
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits2(int n) {
    if (n <= 0) {
        return;
    }
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
}


int main() {
    Print1ToMaxOfNDigits2(5);
    return 0;
}