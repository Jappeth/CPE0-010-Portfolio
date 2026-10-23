#include "sorting.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

const int max_size = 100;

void displayArr(int arr[]);

int main() {
    //unsorted array
    int arr[max_size];
    //time (0) as seed 
    srand(time(0));
    //populate the array
    for (int i = 0; i < max_size; i++) {
        arr[i] = rand() % 100;
    }

    std::cout << "\nUnsorted: \n";
    displayArr(arr);
    
    /***
    std::cout << "\nShell sorted: \n";
    shellSort(arr, max_size);
    displayArr(arr);
    
    std::cout << "\nMerge sorted: \n";
    mergeSort(arr, max_size);
    displayArr(arr); 
    
    std::cout << "\nQuick sorted: \n";
    quickSort(arr, max_size);
    displayArr(arr); 
    ***/
    std::cout << "\nQuick sorted(Custom): \n";
    quickSortCustom(arr, max_size);
    displayArr(arr); 

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < max_size; i++) {
        std::cout << arr[i] << ' ';
    }
}   