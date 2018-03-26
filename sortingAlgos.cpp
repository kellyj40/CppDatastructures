#include <iostream>
using namespace std;

//Declarations of sorting algorithms
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int size);
void mergeArr(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);
void swapPositions(int* a, int* b);
void quickSort(int arr[], int low, int high);
int partitionQuickSort (int arr[], int low, int high);


///////////////////////////-------------- Bubble sort --> loop start to finish until no more swaps occur.------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void bubbleSort(int arr[], int size)
{
    bool swapped = false;
    while(!swapped)
    {
        swapped = true;
        for(int j=1; j<size; j++)
        {
            if(arr[j-1] > arr[j])
            {
                int smaller = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = smaller;
                swapped = false;
            }
        }
    }
    cout<<""<<endl;
}
///////////////////////////-------------- Insertion sort --> ripple effect, continue moving down until cant anymore ------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void insertionSort(int arr[], int size)
{

    for(int i=1; i<size; i++)
    {
        int j = i;
        while(j>0 && arr[j]<arr[j-1])
        {
            //swap the values
            int smaller = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = smaller;
            j--;
        }
    }

    cout<<""<<endl;
}


///////////////////////////-------------- Merge Sort, divide and conquer using splitting and combining ------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//Merges the sorted array together
// l is left index, r right index and m is middle index
void mergeArr(int arr[], int l, int m, int r)
{

    // i, j and k are to keep track of the position of the merging arrays
    int i, j, k;
    // Sizes for the copy arrays from arr
    int n1 = m - l + 1;
    int n2 =  r - m;

    // Make the copy arrays of sizes
    int L[n1], R[n2];

    //Loop to copy, from left pointer in arr
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Now loop and replace arr positions with the copied arrays checking the values
    i = 0; // left pointer
    j = 0; // right pointer
    k = l; // arr pointer

    while(i<n1 && j<n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

//Splits up the array to segments, l is the left index and r is right
void mergeSort(int arr[], int l, int r)
{

    // Split the array at the center, enter in only when the left index is less than the right
    if (l<r)
    {

        // Get the center point
        int m = (l+r)/2;
        //Divide by splitting on m and calling the mergeSort
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        // After merge the arrays together.so they are sorted
        mergeArr(arr, l, m, r);
    }

}




///////////////////////////-------------- Quick Sort, divide and conquer using pivot value ------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void swapPositions(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionQuickSort (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swapPositions(&arr[i], &arr[j]);
        }
    }
    swapPositions(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitionQuickSort(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<""<<endl;
}
