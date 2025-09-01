#include <quicksort.hpp>
#include <heapsort.hpp>

using namespace std;

int main(void){
    HeapSort sorter;
    QuickSort sorter2;
    sorter.setArray({34, 7, 23, 32, 5, 62});
    sorter2.setArray({34, 7, 23, 32, 5, 62});

    cout << "Heap sort sample\n-------------------------------------" << endl;
    sorter.printArray();
    sorter.sort();

    cout << "\nQuick sort sample\n-------------------------------------" << endl;
    sorter.printArray();
    sorter.sort();

    // system("pause");
    return 0;
}