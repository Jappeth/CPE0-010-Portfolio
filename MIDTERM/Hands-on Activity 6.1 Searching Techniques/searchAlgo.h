#include "node.h"

#ifndef SEARCHING_ALGO_H
#define SEARCHING_ALGO_H

/*
Linear search algorithm

N = boundary of list
item = searching 
data = linear array

step 1: I = 0
step 2: repeat while I <=0
    if(item = data[i]) 
        print success
        exit
    else 
        unsuccess
    exit
*/
/*
template <typename A>
int linearSearchAr(int size, A dataFind, A array[]) { //modified to return number of runs
    int i;
    for(i = 0; i < size; i++) {
        if (array[i] == dataFind){
            //std::cout << "Found Successfully in " << i+1 << "th position.\n";
            return i + 1; //return number of passes
        }
    }
    //std::cout << "Item not found.\n";
    return -1;
}
*/

template <typename A>
int linearSearchAr(int size, A dataFind, A array[]) { //modified to return number of copies
    int ins = 0;//no of isntance
    for(int i = 0; i < size; i++) {
        if (array[i] == dataFind){
            //std::cout << "Found Successfully in " << i+1 << "th position.\n";
            ins++; //add to instances
        }
    }
    //std::cout << "Item not found.\n";
    return ins;
}

template<typename A>
int linearSearchLL(Node<A> *nodes, A dataFind) {//modded to return passes
    int i = 1;
    while(nodes != nullptr) {
        if(nodes->data == dataFind){
            //std::cout << "The data: " << dataFind << ", was found successfully.\n";
            return i; //return passes
        }
        nodes = nodes->next;
        i++;
    }
    //std::cout << "Not found.\n";
    return -1;
}

/*
Binary search algo
1. low = 0, up = n-1
2. repeat while low <= up
        mid = int low-up/2
        if 

*/

template<typename A>
void binarySearchAr(A data[], int arrSize, A dataFind) {
    int low = 0, high = arrSize - 1, middle;
    while(low <= high){
        middle = int((high + low)/2);
        if(dataFind == data[middle]){
            std::cout << "The data: " << dataFind << ", was found.\n";
            return;
        } else if(dataFind < data[middle]){
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    std::cout << "Data: " << dataFind << ", was not found.\n";
}

template<typename A>
void recBinarySearchAr(A data[], int low, int high, A dataFind) {//included high and low into parameters
    int middle = (low + high)/2;
    if (low > high){ //check if fail to return immediately 
        std::cout << "The data: " << dataFind << ", was not found.\n";
        return;
    }
    if (data[middle] == dataFind){ //check if found to return immediately
        std::cout << "The data: " << dataFind << ", was found successfully.\n";
        return;
    } else if (dataFind < data[middle]) { //shrink size accordingly with function calls
        recBinarySearchAr(data, low, middle -1, dataFind);
    } else {
        recBinarySearchAr(data, middle +1, high, dataFind);
    }
}

//Binary search LL
//get middle function

template <typename A>
Node<A>* getMiddle(Node<A>* start, Node<A>* last){
    Node<A> *slow = start;
    Node<A> *fast = start;

    //continue until fast = nullptr
    while(fast != last && fast->next != last) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


template <typename A>
void binarySearchLL(Node<A>* start, A dataFind) {
    Node<A>* last = nullptr;

    while (start != last){
        Node<A>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "The data: " << dataFind << ", was found.\n";
            return;
        }else if(middle->data > dataFind) {
            last = middle;
        }else{
            start = middle->next;
        }
    }
    std::cout << "Data: " << dataFind << ", was not found.\n";
}


#endif