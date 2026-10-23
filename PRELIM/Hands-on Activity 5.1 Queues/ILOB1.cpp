#include <iostream>
#include "queueLL.h"

int main() {

    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('R', front, back);
    enqueue('O', front, back);
    enqueue('Y', front, back);
    enqueue('C', front, back);
    enqueue('E', front, back);
    std::cout << "\nTesting if enqueue workedS";
    std::cout << "\nFront: " << front->data << "\tBack: " << back->data;

    std::cout << "\nTesting if dequeue worked";
    dequeue(front, back);
    std::cout << "\nFront: " << front->data << "\tBack: " << back->data;

    std::cout << "\nDisplaying all\n";
    displayAll(front);
    
    std::cout << "\nTesting is empty\n";
    std::cout << (isEmpty(front, back)? "Queue is empty\n" : "Queue is not empty\n");
    std::cout << "\nDeleting all\n";
    dequeue(front, back);
    dequeue(front, back);
    dequeue(front, back);
    dequeue(front, back);
    std::cout << (isEmpty(front, back)? "Queue is empty\n" : "Queue is not empty\n");
    
    return 0;
}