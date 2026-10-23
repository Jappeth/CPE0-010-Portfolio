#ifndef NODE_H
#define NODE_H


template <typename A>
class Node{
    public:
        A data;
        Node* next;

};

template <typename A>
Node<A> *newNode(A newData) {
    Node<A> *newNode = new Node<A>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

#endif