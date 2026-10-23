#include <iostream>
#include <thread>
#include "sorting.h"
#include <chrono>
#include <random>
#include <time.h>

const int max_size = 100000;

int main() {
    /*
    int arr[max_size];
    int arr2[max_size];
    for (int i = 0; i < max_size; i++) {
    arr[i] = i; 
    arr2[i] = i; 
    }

    std::thread insertion(insertionSort<int>, arr, max_size);
    std::thread shell(shellSort<int>, arr2, max_size);
    
    insertion.join();
    shell.join();
    */
    
    int find = 354649514;
    int arr[max_size];
    int arr2[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
    arr[i] = rand() % 100000; 
    arr2[i] = rand() % 100000; 
    }

    std::thread linear(linearSearchAr<int>, max_size, find, arr);
    std::thread binary(binarySearchAr<int>, arr, max_size, find);
    linear.join();
    binary.join();

    return 0;
}