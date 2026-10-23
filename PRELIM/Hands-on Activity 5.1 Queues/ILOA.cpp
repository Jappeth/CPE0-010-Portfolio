#include <iostream>
#include <queue>

void display(std::queue<char> cue);

int main() {
        //create an object
    std::queue<char> myQ;

    //use the enqueue operation
    myQ.push('R');
    myQ.push('O');
    myQ.push('Y');
    myQ.push('C');
    myQ.push('E');

    std::cout << "Front: " << myQ.front() << std::endl;
    std::cout << "Back: " << myQ.back() << std::endl;
    std::cout << "Whole: ";
    display(myQ);
    //use the dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);

    return 0;
}

void display(std::queue<char> cue) {
    if(cue.empty()){
        std::cout << "Queue is empty\n";
    } else {
    std::queue<char> copyCue = cue;
    while(!copyCue.empty()) {
        std::cout << copyCue.front();
        copyCue.pop();
    }
    std::cout << std::endl;}
}
