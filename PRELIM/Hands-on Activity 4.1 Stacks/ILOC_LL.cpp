#include <iostream>

class Node {
    public:
        char data;
        Node* next;

};

Node *head = NULL, *tail = NULL;

void push(char newData) {
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

char pop() {
    char tempVal;
    Node* temp;

    if(head == NULL) {
        head = tail = NULL;
        std::cout << "Stack underflow!\n";
        return 0;
    } else {
        temp = head;
        tempVal = head->data;
        head = head->next;
        delete temp;
        return tempVal;
    }
}

char Top() {
    if(head == NULL) {
        std::cout << "Stack is empty\n";
        return 0;
    } else {
       return head->data;
    }
}

bool matchSymbol(std::string expr) {
    for(char ch : expr) {
        switch(ch) {
            //Opening symbols
            case '(': 
                push(ch);
                break;
            case '{': 
                push(ch);
                break;
            case '[': 
                push(ch);
                break;
            //Closing symbols
            case ')': 
                if(head == NULL || Top() != '('){
                    return false;
                } else {
                    pop();
                    break;
                }
            case '}': 
                if(head == NULL || Top() != '{'){
                    return false;
                } else {
                    pop();
                    break;
                }
            case ']': 
                if(head == NULL || Top() != '['){
                    return false;
                } else {
                    pop();
                    break;
                }
            //Not braces
            default: 
                break;
        }
    }
    bool clear = (head == NULL);
    while (head != NULL) {
        pop();
    }
    return clear;
}


int main() {
    std::string expr1 = "(A+B)+(C-D)";
    std::string expr2 = "((A+B)+(C-D)";
    std::string expr3 = "((A+B)+[C-D])";
    std::string expr4 = "((A+B]+[C-D]}";
    
    std::cout << expr1 << (matchSymbol(expr1)? " - Valid!\n" : " - Error!\n");
    std::cout << expr2 << (matchSymbol(expr2)? " - Valid!\n" : " - Error!\n");
    std::cout << expr3 << (matchSymbol(expr3)? " - Valid!\n" : " - Error!\n");
    std::cout << expr4 << (matchSymbol(expr4)? " - Valid!\n" : " - Error!\n");

    return 0;
}