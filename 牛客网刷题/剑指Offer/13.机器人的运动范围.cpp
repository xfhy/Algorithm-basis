#include <iostream>
#include <cstring>

/*
 * 2017年11月15日18:50:02
 * 面试题13:机器人的运动范围
 * */

int movingCount(int threshold, int rows, int cols);

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited);

bool check(int threshold, int rows, int cols, int row, int col, bool *visited);

int getDigitSum(int number);

/*
去遍历
*/
int movingCount(int threshold, int rows, int cols) {
    int count = 0;
    //声明一个状态数组用于标记当前位置是否以及被遍历过
    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        visited[i] = false;
    }
    count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    return count;
}

//回溯法
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
    int count = 0;
    //检查当前位置是否可行
    if (check(threshold, rows, cols, row, col, visited)) {
        //标记当前位置为已遍历过
        visited[row * cols + col] = true;
        //计数:当前位置(可行)+上下左右
        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);

    }
    return count;
}

//检查这个点是否可以计数
bool check(int threshold, int rows, int cols, int row, int col, bool *visited) {
    //坐标满足 并且 未被标记
    if (row >= 0 && col >= 0 && row < rows && col < cols &&
        getDigitSum(row) + getDigitSum(col) <= threshold &&
        !visited[row * cols + col]) {
        return true;
    }
    return false;
}

//求某个数的坐标和
int getDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// ====================测试代码====================
void test(char *testName, int threshold, int rows, int cols, int expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1() {
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}