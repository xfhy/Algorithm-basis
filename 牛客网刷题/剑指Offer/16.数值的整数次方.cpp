#include <iostream>
#include <cmath>

/*
 * 2017年11月21日20:11:50
 * 面试题16: 数值的整数次方
 * */

using namespace std;

/*--------------------------------------------方式1------------------------------------------------*/

//用全局变量来标注是否出错了
bool g_InvalidInput = false;

//浮点数判断是否相等
bool equals(double a, double b) {
    return abs(a - b) < 0.00001;
}

//这种方式虽然能实现,但是比较笨  进行了很多重复的计算 比如: 32次方 就是 16次方的平方
//  double PowerWithUnsignedExponent1(double base,unsigned int exponent){
//      double result = 1.0;
//      for(int i=1; i<=exponent; i++){
//          result *= base;
//      }
//      return result;
//  }

//可以根据公司进行计算
double PowerWithUnsignedExponent2(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    double result = PowerWithUnsignedExponent2(base, exponent >> 1);  //exponent除2
    result *= result;
    if (exponent & 0x1 == 1) {   //判断奇偶性   如:011是奇数    010是偶数
        result *= base;
    }
    return result;
}

double Power(double base, int exponent) {
    g_InvalidInput = false;

    //如果base为0,那么无意义  当base为0,并且指数为负数时,相当于0的x次方求倒数,这肯定是不允许的
    if (equals(base, 0.0) && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) (exponent);
    if (exponent < 0) {
        absExponent = (unsigned int) (-exponent);
    }

    //去计算base 的 absExponent次方
    double result = PowerWithUnsignedExponent2(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;  //如果指数是负数,则需要求倒
    }
    return result;
}


// ====================测试代码====================
void
Test(const char *testName, double base, int exponent, double expectedResult, bool expectedFlag) {
    double result = Power(base, exponent);
    if (equals(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main() {
// 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);
    return 0;
}