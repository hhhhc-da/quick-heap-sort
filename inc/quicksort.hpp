#include <base.hpp>

#undef TAG
#define TAG "NANOKA_QUICKSORT"

// 极力不推荐在头文件中使用 using namespace std
using namespace std;

class QuickSort{
public:
    void sort(void);

    // 打印数组
    inline const void printArray(void) const {
        cout << "(" << TAG << ") Array: ";
        for (const auto &num : arr){
            cout << num << " ";
        }
        cout << endl;
    }
    // 设置数组
    inline void setArray(const vector<int> &arr){
        lock_guard<mutex> lock(mtx);
        this->arr = arr;
    }
    // 移动数组
    inline void setArray(vector<int> &&arr){
        lock_guard<mutex> lock(mtx);
        this->arr = move(arr);
    }
    // 从C风格数组设置
    inline void setArray(int arr[], int size){
        lock_guard<mutex> lock(mtx);
        this->arr.assign(arr, arr + size);
    }
    // 从初始化列表设置
    inline void setArray(initializer_list<int> arr){
        lock_guard<mutex> lock(mtx);
        this->arr = arr;
    }
    // 交换节点
    inline void swap(int idx, int idx2){
        lock_guard<mutex> lock(mtx);
        int temp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = temp;

        printArray();
    }

private:
    void quickSort(int low, int high);
    vector<int> arr;
    mutex mtx;
};