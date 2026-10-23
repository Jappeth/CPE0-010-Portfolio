#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searchAlgo.h"

const int max_size = 10;

int main() {
    //=================1. ARRAY=============================
    /*
    int arr1[max_size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int find = 18;
    int n = linearSearchAr(max_size, find, arr1);
    if(n > 0){
        std::cout << "It took " << n << " comparison/s to find " << find << std::endl;
    } else {
        std::cout << "Item: " << find << ", not found.\n";
    }
    */
    //===================================================


    //===============1. LINKED LIST=========================
    /*
    Node<int>* num1 = newNode(15);
    Node<int>* num2 = newNode(18);
    Node<int>* num3 = newNode(2);
    Node<int>* num4 = newNode(19);
    Node<int>* num5 = newNode(18);
    Node<int>* num6 = newNode(0);
    Node<int>* num7 = newNode(8);
    Node<int>* num8 = newNode(14);
    Node<int>* num9 = newNode(19);
    Node<int>* num10 = newNode(14);

    num1->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;
    num5->next = num6;
    num6->next = num7;
    num7->next = num8;
    num8->next = num9;
    num9->next = num10;

    int find = 18;
    int n = linearSearchLL(num1, find);
    if(n > 0){
        std::cout << "It took " << n << " comparison/s to find " << find << std::endl;
    } else {
        std::cout << "Item: " << find << ", not found.\n";
    }
    */
    //=====================================================




    //=================2. ARRAY=============================
    /*
    int arr1[max_size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int find = 18;
    int n = linearSearchAr(max_size, find, arr1);
    std::cout << "The data: " << find << ", was found " << n << " times.\n";
    */
    //===================================================




    //===================3. Binary =====================  
    /*
    int arr2[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int find = 8;
    binarySearchAr(arr2, max_size, find);
    */
    //=================================================


    //=====================4. Recursive Binary =================
    int arr2[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int find = 13;
    recBinarySearchAr(arr2, 0, max_size - 1, find); //changed since were taking high and low
    //===========================================================

    return 0;
}