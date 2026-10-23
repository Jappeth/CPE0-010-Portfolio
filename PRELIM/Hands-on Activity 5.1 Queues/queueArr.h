#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename A>
class Queue{
    private:
        A* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;
    
    public:
        Queue(size_t capacity = 10);
        ~Queue();
        Queue(const Queue &other);
        Queue& operator=(const Queue &other);

        bool Empty();
        bool Full();
        size_t Size();
        void Clear();
        A Front();
        A Back();
        void Enqueue(A newData);
        A Dequeue();
        void DisplayAll();
};

template <typename A>
Queue<A>::Queue(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new A[q_capacity];
}

template <typename A>
Queue<A>::Queue(const Queue &other) {
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new A[q_capacity];
        for(int i = 0; i < q_size; i ++){
            int newFront = (q_front + i) % q_capacity;
            q_array[newFront] = other.q_array[newFront];
        }
}

template <typename A>
Queue<A>& Queue<A>::operator=(const Queue<A> &other) {
    if(this != &other) {
        delete[] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new A[q_capacity];
        for(int i = 0; i < q_size; i ++){
            int newFront = (q_front + i) % q_capacity;
            q_array[newFront] = other.q_array[newFront];
        }
    }
    return *this;
}

template <typename A>
Queue<A>::~Queue() {
    delete[] q_array;
}

template <typename A>
bool Queue<A>::Empty() {
         return (q_size == 0);
}

template <typename A>
bool Queue<A>::Full() {
        return (q_size == q_capacity);
}

template <typename A>
size_t Queue<A>::Size() {
        return q_size;
}

template <typename A>
A Queue<A>::Front() {
        if(Empty()) {
            std::cout << "Queue is empty\n";
            return A{};
        }
        return q_array[q_front];
}

template <typename A>
A Queue<A>::Back() {
        if(Empty()) {
            std::cout << "Queue is empty\n";
            return A{};
        }
        return q_array[q_back];
    }

template <typename A>
void Queue<A>::Clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
}

template <typename A>
void Queue<A>::Enqueue(A newData) {
        if(Full()) {
            std::cout << "Queue is full\n";
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = newData;
        q_size++;
}

template <typename A>
A Queue<A>::Dequeue() {
        if(Empty()) {
            std::cout << "Queue is empty\n";
            return A{};
        }
        A temp = q_array[q_front];
        q_front = (q_front + 1) % q_capacity;
        q_size--;

        if(Empty()) Clear();
        return temp;
}

template <typename A>
void Queue<A>::DisplayAll(){
        if(Empty()){
            std::cout << "Queue is empty\n";
            return;
        }
        for(int i = 0; i < q_size; i++){
            std::cout << q_array[(q_front + i) % q_capacity];
        }
        std::cout << std::endl;
}

#endif