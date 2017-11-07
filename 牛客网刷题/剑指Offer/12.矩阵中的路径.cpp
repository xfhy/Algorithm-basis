#include <iostream>
#include <cstring>

bool hasPathCore(const char *matrix, int rows, int cols, int row,
                 int col, const char *str, int &pathLength, bool *visited);

using namespace std;

/*
 * 2017年11月7日18:51:02
 * 面试题12:矩阵中的路径
 * */

bool hasPath(const char *matrix, int rows, int cols, const char *str) {
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    //用于标记当前位置是否被访问过
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;  //当前遍历的位置
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            //从这个位置递归的去遍历
            if (hasPathCore(matrix, rows, cols, row, col, str,
                            pathLength, visited)) {
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

bool hasPathCore(const char *matrix, int rows, int cols, int row,
                 int col, const char *str, int &pathLength, bool *visited) {
    //当已经遍历到字符串的末尾,说明前面的都已经适配了的   这是是成功匹配
    if (str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col]) {
        ++pathLength;

        //标记当前位置已经被访问
        visited[row * cols + col] = true;

        //从这个点出发,遍历4个方向,不断深入
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
                              str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row - 1, col,
                                 str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col + 1,
                                 str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row + 1, col,
                                 str, pathLength, visited);

        if (!hasPath) {  //如果不匹配,则回退
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}


// ====================测试代码====================
void
Test(const char *testName, const char *matrix, int rows, int cols, const char *str, bool expected) {
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1() {
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "BFCE";

    Test("Test1", (const char *) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2() {
    const char *matrix = "ABCESFCSADEE";
    const char *str = "SEE";

    Test("Test2", (const char *) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3() {
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "ABFB";

    Test("Test3", (const char *) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4() {
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char *) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5() {
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char *) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6() {
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char *) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7() {
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char *) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8() {
    const char *matrix = "AAAAAAAAAAAA";
    const char *str = "AAAAAAAAAAAA";

    Test("Test8", (const char *) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9() {
    const char *matrix = "AAAAAAAAAAAA";
    const char *str = "AAAAAAAAAAAAA";

    Test("Test9", (const char *) matrix, 3, 4, str, false);
}

//A

//A
void Test10() {
    const char *matrix = "A";
    const char *str = "A";

    Test("Test10", (const char *) matrix, 1, 1, str, true);
}

//A

//B
void Test11() {
    const char *matrix = "A";
    const char *str = "B";

    Test("Test11", (const char *) matrix, 1, 1, str, false);
}

void Test12() {
    Test("Test12", nullptr, 0, 0, nullptr, false);
}


int main() {
    /*char *matrix = "bfeh";
    char *str = "abtgcfcsjdeh";
    cout << hasPath(matrix, 3, 3, str);*/

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();
    return 0;
}