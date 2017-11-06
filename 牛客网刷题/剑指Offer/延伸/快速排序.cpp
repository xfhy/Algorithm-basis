#include <iostream>

using namespace std;

/*
 * 2017年10月30日18:51:26
 * 快速排序
 * */

//快速排序的一趟循环
//算法：将一个数，比它小的放到该数的前面，比它大的放到该数的后面
//这里的基准数是最传统的选法,直接将第一个作为基准数
int Partition(int a[], int low, int high) {
    int standard = a[low];   //基准数
    while (low < high) {
         //从后往前  遇到比基准数小的就退出循环
        while (low < high && a[high] >= standard) {
            high--;
        }
        a[low] = a[high];  //挖坑

        //从前往后  遇到比基准数大的就退出循环
        while (low < high && a[low] <= standard) {
            low++;
        }
        a[high] = a[low];
    }
    //基准数回归
    a[low] = standard;
    return low;
}

//数组快速排序
void sort(int a[], int low, int high) {
    if (low < high) {
        int pivotloc = Partition(a, low, high);
        sort(a, low, pivotloc - 1);
        sort(a, pivotloc + 1, high);
    }
}

int main() {
    int a[] = {12, 24, 23, 41, 54, 62, 7, 8, 45};
    sort(a, 0, 7);
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}