#include <iostream>

using namespace std;

//二分查找
int binarySerach(int array[], int length, int key) {
    if (array == nullptr || length <= 0) {
        return -1;
    }
    int left = 0;
    int right = length - 1;
    int mid = 0;
    while (left <= right) {  //这里必须为<=  比如1,3,5,我要查找5
        mid = (left + right) / 2;
        if (key == array[mid]) {
            return mid;
        } else if (array[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << binarySerach(a, 8, 8);
    return 0;
}