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
            if(arr[i] > arr[j]){ //compare adjacent 
                std::swap(arr[j], arr[i]); // swap if necessary     
            }
        }
    }
}

template<typename T>
int routineSmallest(T arr[], int K, const int arrSize) { //array, current index, arrsize
    int position = K;
    T smallest = arr[K]; //assumes arr[K] is the smallest value

    for (int j = K + 1; j < arrSize; j++) { //find smaller value
        if (arr[j] < smallest){
            smallest = arr[j];
            position = j;
        }
    }
    return position; //gives index of smallest value
}

template<typename T>
void selectionSort(T arr[], size_t arrSize) {
    int pos, pass;
    T temp;
    for(int i = 0; i < arrSize; i++) {
        pos = routineSmallest(arr, i, arrSize); //gets index of smallest
        std::swap(arr[i], arr[pos]); //swap current end of sorted part to smallest
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize) {
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

}

//===========================Part2==============================================

template<typename T>
void shellSort(T arr[], size_t arrSize) {
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
}

template<typename T>
void merge(T arr[], int left, int middle, int right) {
    int i = left, j = middle + 1, k = left; 
    T* temp = new T[right + 1]; //temp array with size of right+1

    while(i <= middle && j <= right) { //merging element in order
        if(arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; //if sorted, copy, move forward
        } else {
            temp[k++] = arr[j++]; //if not sorted, get the other sub-array's first element
        }
    }

    while (i <= middle) { //insert all remaining left elements
        temp[k++] = arr[i++];
    }

    while (j <= right) { //insert all remaining right elements
        temp[k++] = arr[j++];
    }

    for(int l = left; l <= right; l++) { //copy the sorted temp array
        arr[l] = temp[l];
    }

    delete[] temp; //clear temp memory

}

template<typename T>
void mergeSorter(T arr[], int left, int right){
    if(left < right) {
        int middle = (right + left) / 2;

        mergeSorter(arr, left, middle); //sorting first half first recursively
        mergeSorter(arr, middle + 1, right); //sorting second half next recursively
        merge(arr, left, middle, right); //merge sorted halves
    }
}

template<typename T>
void mergeSort(T arr[], size_t arrSize) {
    if(arrSize <= 1) {
        std::cout << "Array is already sorted.\n";
    } else {
        mergeSorter(arr, 0, arrSize - 1);
    }
}

template<typename T>
int partition(T arr[], int left, int right){
    T pivot = arr[right]; //gets pivot value
    int i = left - 1; //i to -1 or before first element of unsorted part of array

    for (int j = left; j < right; j++) {//go through array
        if (arr[j] <= pivot) { //if j < pivot, 
            i++; //increment, 
            std::swap(arr[i], arr[j]); //then swap(i,j)
        }
    }
    std::swap(arr[i + 1], arr[right]); //after j reaches pivot, swap pivot to i+1th element
    return ++i; //give the pivot's position
}

template<typename T>
void quickSorter(T arr[], int left, int right) {
    if(left < right) {
        int pivotIndex = partition(arr, left, right); //first gets the pivotIndex's proper place
        quickSorter(arr, left, pivotIndex - 1); //repeats process on the left side of the initial correct pivotIndex
        quickSorter(arr, pivotIndex + 1, right); // repeats process until the whole right side is also sorted
    }
}

template<typename T>
void quickSort(T arr[], size_t arrSize) {
   if(arrSize <= 1) {
        std::cout << "Array is already sorted.\n";
    } else {
        quickSorter(arr, 0, arrSize - 1);
    }
}


//=====================SUPPLEMENRTARY============================
template<typename T>
int partitionCustom(T arr[], int left, int right){
    T pivot = arr[right]; //gets pivot value
    int i = left - 1; //i to -1 or before first element of unsorted part of array

    for (int j = left; j < right; j++) {//go through array
        if (arr[j] <= pivot) { //if j < pivot, 
            i++; //increment, 
            std::swap(arr[i], arr[j]); //then swap(i,j)
        }
    }
    std::swap(arr[i + 1], arr[right]); //after j reaches pivot, swap pivot to i+1th element
    return ++i; //give the pivot's position
}

template<typename T>
void quickSorterCustom(T arr[], int left, int right) {
    if(left < right) {
        int pivotIndex = partitionCustom(arr, left, right); //first gets the pivotIndex's proper place
        int leftSubArray = pivotIndex - left;
        int rightSubArray = right - pivotIndex;
        if(leftSubArray > 1) {
            insertionSort(arr + left, leftSubArray);
        }
        if(rightSubArray > 1) {
             insertionSort(arr + (pivotIndex + 1), rightSubArray);
        }
    
    }
}

template<typename T>
void quickSortCustom(T arr[], size_t arrSize) {
   if(arrSize <= 1) {
        std::cout << "Array is already sorted.\n";
    } else {
        quickSorterCustom(arr, 0, arrSize - 1);
    }
}

#endif