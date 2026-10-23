#ifndef SORTING_H
#define SORTING_H
#include <cstddef>
#include <iostream>
#include <chrono>
#include <iostream>

//==========================sorters========================================

template<typename T>
void insertionSort(T arr[], size_t arrSize) {
    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();

    //function call
    int k = 0, j; //initialize k as arr front
    T temp; //storage of arr[k]

    while(k < arrSize) {//loops through the whole array
        temp = arr[k]; //sets temp as arr[k]
        j = k-1; //j as before k

        while(j >= 0 && temp < arr[j]){ //makes sure j >= 0 and checks if it's less than arr[k]
            arr[j+1] = arr[j]; //moves arr[j] forward
            j--; //goes back one element
        } //shifting other elements forward for temp's place

        arr[j+1] = temp;
        k++;
    }

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nTime taken: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
    " nanoseconds (Insertion sort)" << std::endl;

}


template<typename T>
void shellSort(T arr[], size_t arrSize) {
    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();

    //function call
    for(int gap = arrSize/2; gap > 0; gap /= 2) {//gets a gap(half arr size), then halves again after loop
        for(int i = gap; i < arrSize; i++) {//iterates from gap to end
            T temp = arr[i]; //stores arr[gap] value 
            int j = i; //gets gap index

            while(j >= gap && arr[j - gap] > temp) {//checks if gap and front needs swapping
                arr[j] = arr[j - gap]; //moves front into gap
                j -= gap; //sets j as front index, and stops loop
            }
            arr[j] = temp; //sets front as the gap value
        }
    }

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
    " nanosecond(Shell sort)" << std::endl;
}



//==========================searchers==================================
template <typename A>
void linearSearchAr(int size, A dataFind, A array[]) { 
    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for(int i = 0; i < size; i++) {
        if (array[i] == dataFind){
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Found in: " <<
            std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
            " nanosecond(Linear)";
            return;
        }
    }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Not found in: " <<
        std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
        " nanosecond(Linear)";   
    return;
}


template<typename A>
void binarySearchAr(A data[], int arrSize, A dataFind) {
    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = int(low + (high - low)/2);
        if(dataFind == data[middle]){
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Found in: " <<
            std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
            " nanosecond(Binary)";   
            return;
        } else if(dataFind < data[middle]){
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Not found in: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<
    " nanosecond(Binary)";   
}

#endif