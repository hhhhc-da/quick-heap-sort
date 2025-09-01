#include <heapsort.hpp>

// 快速排序主函数
void HeapSort::sort(void)
{
    lock_guard<mutex> lock(mtx);
    if (arr.size() <= 1)
        return;

    for (int i = 0; i < arr.size(); ++i){
        heapSort(arr.size() - i - 1);
        if (i < arr.size() - 1)
            swap(0, arr.size() - i - 1);
    }
}

// 内部交换函数
void HeapSort::heapSort(int end)
{
    // 大根堆
    if (end <= 0)
        return;

    int ps = end, ft; // 从后往前与父节点迭代比较

    // 单根节点
    if (ps % 2 == 1){
        int fidx = arr.calculateFather(ps);
        if (arr[ps] > arr[fidx])
            swap(ps, fidx);
        ps -= 1; // 处理完了最后一个
    }

    while (ps > 0){ // ps == 0 是根节点
        pair<int, int> min_child = nanoka::max(arr[ps-1], arr[ps]);
        int idx = ps - 1 + min_child.first, fidx = arr.calculateFather(ps);
        
        if (arr[idx] > arr[fidx])
            swap(idx, fidx);

        ps -= 2;
    }
}