#include <iostream>

using namespace std;

/*
 * 2017年11月1日21:38:46
 * 求斐波拉契序列第n项
 * */

/**
 * 千万不要用这种方式(递归),很多重复的计算
 */
long long Fibonacci(unsigned int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/**
 * 递推的方式,比较推荐  从小到大,避免了重复
 * @param n
 * @return
 */
long long Fibonacci2(unsigned int n) {
    int result[] = {0, 1};
    if (n < 2) {
        return result[n];
    }
    long long f1 = 1;
    long long f2 = 1;
    long long f3 = f1 + f2;
    for (unsigned int i = 2; i < n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main() {
    //0 1 1 2 3 5
    cout << Fibonacci2(10);

    return 0;
}