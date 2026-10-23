#ifndef SORTING_H
#define SORTING_H
#include <cstddef>
#include <iostream>

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    //for loop to repeat inner loop
    for(int i = 0; i < arrSize; i++) {
        //inner loop that for k = i
        for(int j = i+1; j < arrSize; j++) {
            if(arr[i] > arr[j]){
                std::swap(arr[j], arr[i]);         
            }
        }
    }
}

template<typename T>
int routineSmallest(T arr[], int K, const int arrSize) { //array, current index, arrsize
    int position = K;
    T smallest = arr[K];

    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallest){
            smallest = arr[j];
            position = j;
        }
    }
    return position;
}

template<typename T>
void selectionSort(T arr[], size_t arrSize) {
    int pos, pass;
    T temp;
    for(int i = 0; i < arrSize; i++) {
        pos = routineSmallest(arr, i, arrSize);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize) {
    int k = 0, j;
    T temp;

    while(k < arrSize) {
        temp = arr[k];
        j = k-1;

        while(j >= 0 && temp < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
        k++;
    }

}

#endif