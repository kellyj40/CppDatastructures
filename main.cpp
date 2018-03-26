#include <iostream>
#include "sortingAlgorithms"
#include "Node.h"
#include "LinkedList.h"


using namespace std;

int testSortingAlgorithms();

int main()
{
    LinkedList linked_list;
    linked_list.add(2);
    linked_list.add(6);
    cout << "Address: "<< linked_list.head << ", and the value is :" << linked_list.head -> value << endl;
    //testSortingAlgorithms();
}


int testSortingAlgorithms(){

    int size = 15;
    int arr[15] = {1, 2, 3, 4, 10, 11, 12, 13, 5, 6, 7, 8, 14, 15, 9};

    bubbleSort(arr, size);
    insertionSort(arr, size);
    mergeSort(arr, 0, size-1);
    quickSort(arr, 0, size-1);

    return 0;

}
