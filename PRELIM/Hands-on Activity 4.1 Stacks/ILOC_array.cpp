#include <iostream>
#include <string>

//global declaration
#define maxCap 10
char stackArr[maxCap];
int top = -1;
int newData;

//prototype functions
void push(char newData);
char pop();
char Top();
bool isEmpty();
bool matchSymbol(std::string expr);


int main() {
    std::string expr1 = "(A+B)+(C-D)";
    std::string expr2 = "((A+B)+(C-D)";
    std::string expr3 = "((A+B)+[C-D])";
    std::string expr4 = "((A+B]+[C-D]}";

    top = -1; //making sure stack is empty before running
    std::cout << expr1 << (matchSymbol(expr1)? " - Valid!\n" : " - Error!\n");
    top = -1;
    std::cout << expr2 << (matchSymbol(expr2)? " - Valid!\n" : " - Error!\n");
    top = -1;
    std::cout << expr3 << (matchSymbol(expr3)? " - Valid!\n" : " - Error!\n");
    top = -1;
    std::cout << expr4 << (matchSymbol(expr4)? " - Valid!\n" : " - Error!\n");

    return 0;
}


//function definition
bool isEmpty() {
    if(top == -1) return true;
    return false;
}

void push(char newData) {
    stackArr[++top] = newData;
}

char pop() {
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return 0;
    }
    char temp = stackArr[top];
    top--;
    return temp;
}

char Top() {
    if(isEmpty()) {
        std::cout << "\nStack is empty!!!";
        return 0;
    }
    return stackArr[top];
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
                if(isEmpty() || Top() != '('){
                    return false;
                } else {
                    pop();
                    break;
                }
            case '}': 
                if(isEmpty() || Top() != '{'){
                    return false;
                } else {
                    pop();
                    break;
                }
            case ']': 
                if(isEmpty() || Top() != '['){
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
    //return after whole string is read
    if(isEmpty()) return true;
    return false;
}