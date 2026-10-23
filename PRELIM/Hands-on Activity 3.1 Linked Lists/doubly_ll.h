#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename A>
class DoubleList {
    public:
        A data;
        DoubleList<A>* prev;
        DoubleList<A>* next;
};

//create new node
template <typename A>
DoubleList<A>* CreateNewNode(A newData) {
    DoubleList<A>* newNode = new DoubleList<A>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

//Traverse print
template <typename A>
void dllTraverse(DoubleList<A>* currentNode){
    //temp variable to store the last node visited
    DoubleList<A> *tail;

    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    //move forward
    std::cout << "\nForward\n";
    while(currentNode != nullptr){
        std::cout<< currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << "\nBackward\n";

    while(tail != nullptr){
        std::cout<< tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

//insert at head
template <typename A>
void dllInsertHead(A newData, DoubleList<A>*& currentHead) {
    //Announce
    std::cout<<"\nInserting '" << newData << "' at the head";
    //create new node
    DoubleList<A>* newNode = CreateNewNode(newData);
    //newnode point to current head
    newNode->next = currentHead;
    //current head point prev to newnode
    currentHead->prev = newNode;
    //update the pointer head
    currentHead = newNode;
}

//Insert at tail
template <typename A>
void dllInsertEnd(A newData, DoubleList<A>* currentNode) {
    //Announce
    std::cout<<"\nInserting '" << newData << "' at the end";
    //create new node
    DoubleList<A>* newNode = CreateNewNode(newData);
    //find tail
    while(currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    //connect last node to new node
    currentNode->next = newNode;
   
    newNode->prev = currentNode;
}

//General Insert
template <typename A>
void dllGeneralInsert(A newData, DoubleList<A>* prevNode) {
    //Announce
    std::cout<<"\nInserting '" << newData << "' after " << prevNode->data;
    //temp for next node
    DoubleList<A>* nextNode;
    //Check if prev node is null
    if(prevNode == nullptr) {
        std::cout << "Previous value cannot be null...\n";
        return;
    }
    //create newNode
    DoubleList<A>* newNode = CreateNewNode(newData);
    //temp next node
    nextNode = prevNode->next;

    //point prevnode to newnode
    prevNode->next = newNode;
    newNode->prev = prevNode;

    //point newnode to next and back
    newNode->next = nextNode;
    nextNode->prev = newNode;
}  

//Delete Node
template <typename A>
void dllDeleteNode(A findData, DoubleList<A>*& start) {
    //Announce
    std::cout<<"\nDeleting '" << findData <<'\'';
    //if theres nothing to delete
    if(start == nullptr) {
        std::cout << "\nNo data to delete\n";
        return;
    }

    DoubleList<A>* currNode = start;

    //data doesnt exist or found
    while(currNode != nullptr && currNode->data != findData) {
        currNode = currNode->next;
    }

    //data not found
    if(currNode == nullptr) {
        std::cout << "Data was not found...\n";
        return;
    }

    //data found at head
    if(currNode->prev == nullptr) {
        start = currNode->next;
        if (start != nullptr) {
          start->prev = nullptr;
        }
    //at tail
    }else if(currNode->next == nullptr) {
        currNode->prev->next = nullptr;
    //at middle
    }else {
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}

#endif