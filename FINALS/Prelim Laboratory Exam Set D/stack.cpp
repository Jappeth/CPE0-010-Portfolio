#include "Stack.h"
#include <iostream>

int main() {

    int choice;
    while(choice != 2){
        std::cout << "\nSymmetry Identifier\n";
        std::cout << "1. Enter values\n";
        std::cout << "2. Exit\n";
        std::cin >> choice;

        switch(choice){
            case 1: push();
                    break;
            case 2: break;
            default: std::cout << "\nPlease enter a valid choice\n";
        }
    }
    displayStack();
    std::cout << "\nThe stack is ";
    std::cout << (compare()? "symmetrical.\n" : "not symmetrical.\n");

    return 0;
}