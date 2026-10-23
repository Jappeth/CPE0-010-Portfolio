#ifndef SUPP_DLL_H
#define SUPP_DLL_H

template <typename A>
class DoubleList {
    public:
        A data;
        DoubleList<A>* prev;
        DoubleList<A>* next;
};

//create new node
template <typename A>
DoubleList<A>* AddSong(A newData) {
    DoubleList<A>* newNode = new DoubleList<A>;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

//Play from start
template <typename A>
void PlayList(DoubleList<A>* start){
    //temp variable to store the last node visited
    DoubleList<A> *tail;

    //check if the list is empty
    if(start == nullptr){
        std::cout<<"The list is empty"<<std::endl;
        return;
    }
    //print
    std::cout << "\nSongs: \n";
    while(start != nullptr){
        std::cout<< start->data << std::endl;
        tail = start;
        start = start->next;
    }
}

//play from end
template <typename A>
void ReversePlay(DoubleList<A>* start) {
    std::cout << "\nPlaying from the end\n";
    DoubleList<A>* temp = start;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    while(temp != nullptr) {
        std::cout << temp->data << '\n';
        temp = temp->prev;
    }
}

//insert at head
template <typename A>
void InsertStart(A newData, DoubleList<A>*& currentHead) {
    //Announce
    std::cout<<"\nInserting '" << newData << "' at the head";
    //create new node
    DoubleList<A>* newNode = AddSong(newData);
    //newnode point to current head
    newNode->next = currentHead;
    //current head point prev to newnode
    currentHead->prev = newNode;
    //update the pointer head
    currentHead = newNode;
}

//Insert at tail
template <typename A>
void InsertEnd(A newData, DoubleList<A>* currentNode) {
    //Announce
    std::cout<<"\nInserting '" << newData << "' at the end";
    //create new node
    DoubleList<A>* newNode = AddSong(newData);
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
void InsertAfter(A newData, DoubleList<A>* prevNode) {
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
    DoubleList<A>* newNode = AddSong(newData);
    //temp next node
    nextNode = prevNode->next;

    //point prevnode to newnode
    prevNode->next = newNode;
    newNode->prev = prevNode;

    //point newnode to next and back
    newNode->next = nextNode;
    if (nextNode != nullptr) {
    nextNode->prev = newNode;
}
}  

//Delete Node
template <typename A>
void DeleteSong(A findData, DoubleList<A>*& start) {
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

//looping list
template <typename A>
void LoopTimes(int n, DoubleList<A>* start) {
    std::cout << "\nLooping " << n << " times.\n";
    DoubleList<A>* temp = start;
    for(int i = 0; i < n; i++){
        while(temp != nullptr) { 
            std::cout << temp->data << '\n';
            temp = temp->next;
        }
        temp = start; //making sure it loops back to start
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}
#endif