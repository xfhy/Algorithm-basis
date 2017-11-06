#include <iostream>

int MinInOrder(int *pInt, int length);

using namespace std;

/*
 * 2017年11月6日17:09:10
 * 面试题11:旋转数组中最小数字
 * */

//查找旋转数组中的最小
int min(int a[], int length) {
    if (a == nullptr || length <= 0) {
        return -1;
    }
    int left = 0;
    int right = length - 1;
    int mid = left;
    while (a[left] >= a[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }

        // 如果数组是 形如 1 1 1 0 1   left,mid,right是一样的时候   只能使用顺序查找
        if (a[left] == a[right] && a[right] == a[mid]) {
            return MinInOrder(a, length);
        }

        mid = (left + right) / 2;
        if (a[mid] <= a[right]) {
            right = mid;
        } else if (a[mid] >= a[left]) {
            left = mid;
        }

    }
    return a[mid];
}

int MinInOrder(int pInt[], int length) {
    int result = pInt[0];
    for (int i = 0; i < length; ++i) {
        if (result > pInt[i]) {
            result = pInt[i];
        }
    }
    return result;
}

int main() {
    int a[] = {3, 4, 5, 6};
    int b[] = {1,1,1,0,1};
    cout << min(a, 5)<<endl;
    cout << min(b, 5);
    return 0;
}