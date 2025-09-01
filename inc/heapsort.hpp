#include <base.hpp>

// 极力不推荐在头文件中使用 using namespace std
using namespace std;

class HeapSort;

// 其实是完全二叉树
class HeapTree {
    // 友元声明保证封闭
    friend class HeapSort;

public:
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

    // 计算子节点地址
    inline pair<int, int> calculateChild(int idx){
        int left = 2 * idx + 1, right = 2 * idx + 2;
        return {left, right};
    }
    // 计算父节点地址
    inline int calculateFather(int idx){
        if (idx <= 0)
            return -1;
        int base = idx;
        if (idx % 2 == 0)
            base -= 1;
        return (base - 1) / 2;
    }
    // 交换节点
    inline void swap(int idx, int idx2){
        lock_guard<mutex> lock(mtx);
        int temp = arr[idx];
        arr[idx] = arr[idx2];
        arr[idx2] = temp;
    }
    // 统计
    inline const size() const {
        return arr.size();
    }

    // 运算符
    int &operator[](int idx){
        return arr[idx];
    }

private:
    vector<int> arr;
    mutex mtx;
    string TAG = "HEAP SORT";
};

class HeapSort{
public:
    void sort(void);

    // 打印数组
    inline const void printArray(void) const {
        arr.printArray();
    }
    // 设置数组
    inline void setArray(const vector<int> &arr){
        lock_guard<mutex> lock(mtx);
        this->arr.setArray(arr);
    }
    // 移动数组
    inline void setArray(vector<int> &&arr){
        lock_guard<mutex> lock(mtx);
        this->arr.setArray(arr);
    }
    // 从C风格数组设置
    inline void setArray(int arr[], int size){
        lock_guard<mutex> lock(mtx);
        this->arr.setArray(arr, size);
    }
    // 从初始化列表设置
    inline void setArray(initializer_list<int> arr){
        lock_guard<mutex> lock(mtx);
        this->arr.setArray(arr);
    }
    // 交换节点
    inline void swap(int idx, int idx2){
        lock_guard<mutex> lock(mtx);
        arr.swap(idx, idx2);
        printArray();
    }

private:
    void heapSort(int end);
    HeapTree arr;
    mutex mtx;
    string TAG = "HEAP SORT";
};