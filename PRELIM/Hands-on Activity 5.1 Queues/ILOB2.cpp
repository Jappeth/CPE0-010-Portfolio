#include <iostream>
#include "queueArr.h"


int main() {
    Queue<char> q(5);
    std::cout << "Enqueueing: ROYCE\n";
    q.Enqueue('R');
    q.Enqueue('O');
    q.Enqueue('Y');
    q.Enqueue('C');
    q.Enqueue('E');

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;

    std::cout << "Queue: ";
    q.DisplayAll();

    Queue<char> r = q;
    std::cout << "Copied Array: \n";
    r.DisplayAll();

    Queue<char> s;
    s = q;
    std::cout << "Copy Assigned Array: \n";
    s.DisplayAll();

    std::cout << "Dequeued: " << q.Dequeue() << std::endl;
    q.DisplayAll();
    std::cout << "Dequeued: " << q.Dequeue() << std::endl;
    q.DisplayAll();
    std::cout << "Dequeued: " << q.Dequeue() << std::endl;
    q.DisplayAll();
    std::cout << "Dequeued: " << q.Dequeue() << std::endl;
    q.DisplayAll();
    std::cout << "Dequeued: " << q.Dequeue() << std::endl;
    q.DisplayAll();
    std::cout << "Is queue empty? " << ((q.Empty()) ? "Yes" : "No") << std::endl;
 
    return 0;
}