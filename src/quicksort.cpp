#include <quicksort.hpp>

// 快速排序主函数
void QuickSort::sort(void){
    lock_guard<mutex> lock(mtx);
    if (arr.size() <= 1) return;

    quickSort(0, arr.size() - 1);
}

// 内部交换函数
void QuickSort::quickSort(int low, int high){
    if (low >= high) return;

    uint8_t drt = 1; // 方向，1表示从右向左，0表示从左向右
    int i = low, j = high, t;

    while (i < j){
        if (drt){ // 从右向左
            if (arr[j] < arr[i]){
                swap(i, j);
                drt ^= 1U;
            }
            else
                --j;
        }
        else { // 从左往右
            if (arr[i] > arr[j]){
                swap(i, j);
                drt ^= 1U;
            }
            else
                ++i;
        }
    }

    quickSort(low, i - 1);
    quickSort(i + 1, high);
}