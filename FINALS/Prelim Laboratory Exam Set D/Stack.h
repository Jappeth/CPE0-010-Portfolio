#ifndef STACK
#define STACK

#include <iostream>

//global declaration
#define maxCap 10
int stackArr[maxCap];
int top = -1;
int newData;
//prototype functions
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayStack();
bool compare();


//function definition
bool isEmpty() {
    if(top == -1) return true;
    return false;
}

bool isFull() {
    if (top == maxCap - 1) return true;
    return false;
}

void push() {
    //check error
    if(isFull()) {
        std::cout << "\nStack overflow!!!";
    }
    std::cout << "\nEnter value: ";
    std::cin >> newData;
    stackArr[++top] = newData;    
}

void pop() {
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return;
    }
    //display value
    std::cout << "\nPopping: " << stackArr[top];
    //decrement top value from the stack
    top--;

}

void Top() {
    //error
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return;
    }
    std::cout << "\nTop of the stack: " << stackArr[top];
}


void displayStack() {
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return;
    }
    std::cout << "\nStack: [ ";
    for(int i = top; i != -1; i--) {
        std::cout << stackArr[i] << ' ';
    }
    std::cout << ']';
}

bool compare(){ //compareing forward and backward
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return false;
    }
    std::string forward, backward; //storing array into strings
    for(int i = top; i != -1; i--) { //backward read
        backward += stackArr[i];
    }
    for(int i = 0; i <= top; i++) { //forward read
        forward += stackArr[i];
    }
    return forward == backward; //compare strings
}

#endif