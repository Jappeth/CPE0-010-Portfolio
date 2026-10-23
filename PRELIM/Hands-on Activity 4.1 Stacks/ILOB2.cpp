#include <iostream>

class Node {
    public:
        int data;
        Node* next;

};

Node *head = NULL, *tail = NULL;

void push(int newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;

    if(head == NULL){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

int pop() {
    int tempVal;
    Node* temp;

    if(head == NULL) {
        head = tail = NULL;
        std::cout << "Stack underflow!\n";
        return -1;
    } else {
        temp = head;
        tempVal = head->data;
        head = head->next;
        delete temp;
        return tempVal;
    }
}

void Top() {
    if(head == NULL) {
        std::cout << "Stack is empty\n";
    } else {
        std::cout << head->data << std::endl;
    }
}

void displayStack() {
    if(head == NULL) {
        std::cout << "Stack underflow!\n";
    } else {
        Node* temp = head;
        while(temp != NULL) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
}

int main() {
    push(1);
    std::cout << "After the first PUSH top of stack is: ";
    Top();

    push(5);
    std::cout << "After the second PUSH top of stack is: ";
    Top();

    pop();
    std::cout << "After the first POP operation, top of stack is: ";
    Top();

    pop();
    std::cout << "After the second POP operation, top of stack is: ";
    Top();

    pop();

    std::cout << "\nPushing 1 to 5 into the stack: \n";
    push(1);
    Top();
    push(2);
    Top();
    push(3);
    Top();
    push(4);
    Top();
    push(5);
    Top();
    std::cout << "\nTesting print stack: \n";
    displayStack();

    return 0;
}