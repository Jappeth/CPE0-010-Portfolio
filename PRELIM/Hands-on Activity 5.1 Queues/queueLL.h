#ifndef QUEUELL_H
#define QUEUELL_H

//class node 
template<typename A>
class qNode{
    public:
        A data;
        qNode* next;
};

//new node creator
template<typename A>
qNode<A>* createNode(A newData) {
    //allocate spcace
    qNode<A>* newNode = new qNode<A>;
    //store new data
    newNode->data = newData;
    //point newnode to null
    newNode->next = nullptr;

    return newNode;
}

//enqueue
template<typename A>
void enqueue(A newData, qNode<A>*& frontPtr, qNode<A>*& backPtr) {
    //create new Node
    qNode<A>* newNode = createNode(newData);
    //check if empty
    if(frontPtr == nullptr && backPtr == nullptr){
        frontPtr = newNode;
        backPtr = newNode;
        return;
    }
    //insert at the back
    backPtr->next = newNode;
    backPtr = newNode;
}
//dequeue
template<typename A>
void dequeue(qNode<A>*& frontPtr, qNode<A>*& backPtr) {
    //check if queue is empty
    if(frontPtr == nullptr && backPtr == nullptr) {
        std::cout << "\nThe queue is empty\n";
        return;
    }
    //create a temp var to store node to be deleted
    qNode<A>* delTemp = nullptr;
    //assign front to temp
    delTemp = frontPtr;
    //check if only one element
    if(frontPtr->next == nullptr && backPtr->next == nullptr){
        frontPtr = nullptr;
        backPtr = nullptr;   
        delete delTemp;
        return;     
    }

    frontPtr = frontPtr->next;
    delTemp->next = nullptr;
    delete delTemp;
}

//display all
template <typename A>
void displayAll(qNode<A>*& front) {
    qNode<A>* temp = front;
    while(temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

//isempty
template <typename A>
bool isEmpty(qNode<A>*& frontPtr, qNode<A>*& backPtr) {
    if(frontPtr == nullptr && backPtr == nullptr) return true;
    return false;
}

#endif