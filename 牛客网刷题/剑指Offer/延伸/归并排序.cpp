#include <iostream>

using namespace std;

/*
 * 2017年10月27日18:32:28
 * 归并排序
 * */

/*
 * 在每次合并过程中，都是对两个有序的序列段进行合并，然后排序。
这两个有序序列段分别为 R[low, mid] 和 R[mid+1, high]。
先将他们合并到一个局部的暂存数组R2中，带合并完成后再将R2复制回R中。
为了方便描述，我们称 R[low, mid] 第一段，R[mid+1, high] 为第二段。
每次从两个段中取出一个记录进行关键字的比较，将较小者放入R2中。最后将各段中余下的部分直接复制到R2中。
经过这样的过程，R2已经是一个有序的序列，再将其复制回R中，一次合并排序就完成了。
 * */

/**
 * 一次合并
 * @param array 数组
 * @param low 第一段的最低索引
 * @param mid 第二段的最低索引-1
 * @param high 这两段的最后索引
 */
void merge(int array[], int low, int mid, int high) {
    int array2[high - low + 1]; //用来临时存储的数组
    int i = low;  //第一段的最低索引
    int j = mid + 1; //第二段的最低索引
    int k = 0; //临时数组的最低索引

    // 扫描第一段和第二段序列，直到有一个扫描结束
    while (i <= mid && j <= high) {
        // 判断第一段和第二段取出的数哪个更小，将其存入合并序列，并继续向下扫描
        if (array[i] <= array[j]) {
            array2[k] = array[i];
            k++;
            i++;
        } else {
            array2[k] = array[j];
            k++;
            j++;
        }
    }

    // 若第一段序列还没扫描完，将其全部复制到合并序列
    while (i <= mid) {
        array2[k] = array[i];
        k++;
        i++;
    }

    // 若第二段序列还没扫描完，将其全部复制到合并序列
    while (j <= high) {
        array2[k] = array[j];
        k++;
        j++;
    }

    // 将合并序列复制到原始序列中
    for (k = 0, i = low; i <= high; i++, k++) {
        array[i] = array2[k];
    }
}

/**
 * 在某趟归并中，设各子表的长度为gap，则归并前R[0...n-1]中共有n/gap个有序的子表：R[0...gap-1], R[gap...2*gap-1], ... , R[(n/gap)*gap ... n-1]。

调用Merge将相邻的子表归并时，必须对表的特殊情况进行特殊处理。

若子表个数为奇数，则最后一个子表无须和其他子表归并（即本趟处理轮空）：若子表个数为偶数，则要注意到最后一对子表中后一个子表区间的上限为n-1。
 * @param array
 * @param gap    分组长度
 * @param length
 */
void mergePass(int array[], int gap, int length) {
    int i = 0;
    // 归并gap长度的两个相邻子表
    for (i = 0; i + gap * 2 - 1 < length; i = i + gap * 2) {
        merge(array, i, i + gap - 1, length);
    }

    // 余下两个子表，后者长度小于gap
    if (i + gap - 1 < length) {
        merge(array, i, i + gap - 1, length - 1);
    }
}

void sort(int array[], int length) {
    for (int gap = 1; gap < length; gap = gap * 2) {
        mergePass(array, gap, length);
    }
}

int main() {
    int a[] = {12, 24, 23, 41, 54, 62, 7, 8,45};
    sort(a, 8);
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << endl;
    }
    return 0;
}