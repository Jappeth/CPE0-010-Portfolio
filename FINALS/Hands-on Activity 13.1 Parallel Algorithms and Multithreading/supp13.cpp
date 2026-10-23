#include <iostream>
#include <thread>

int global;

void add(int n) {
    global += n;
}

int main() {
    std::cout << "Starting global value: " << global << std::endl;
    std::thread t1(add, 3);
    std::thread t2(add, 6);
    std::thread t3(add, 9);

    std::cout << "Current global value: " << global << std::endl;
    t1.join();
    std::cout << "Current global value: " << global << std::endl;
    t2.join();
    std::cout << "Current global value: " << global << std::endl;
    t3.join();
    std::cout << "Current global value: " << global << std::endl;

    return 0;
}