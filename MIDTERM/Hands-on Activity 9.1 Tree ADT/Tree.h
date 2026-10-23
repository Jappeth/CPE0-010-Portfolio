#ifndef TREE_H
#define TREE_H
#include <iostream>

const int maxChildren = 10;

template <typename T>
class Tree{
    private:
        T data; //data
        Tree<T>* children[maxChildren]; //pointer array to children
    public:
        Tree(T data); //constructor
        void insert(T data); //insert new child
        Tree<T>* getChild(T matchData);
        T getValue();
        void setValue(T newData);
        bool isLeaf();

        //traverse
        void preOrder();
        void postOrder();
        void inOrder();
        bool findData(int choice, T findData);
};

template <typename T>
Tree<T>::Tree(T newData) {
    data = newData;
    for (int i = 0; i < maxChildren; i++) {
        children[i] = nullptr;
    }
}

template <typename T>
void Tree<T>::insert(T data) {
    for(int i = 0; i < maxChildren; i++) {//loop thru array of children
        if(children[i] == nullptr) {//insert at first nullpointer
            children[i] = new Tree<T>(data);
            return;
        }
    }
    std::cout << "\nThere's no more children slot\n"; //print if didn't return
}

template <typename T>
Tree<T>* Tree<T>::getChild(T matchData) {
    for(int i = 0; i < maxChildren; i++) {
        if(children[i] != nullptr && children[i]->data == matchData) {
            return children[i];
        }
    }
    std::cout << "Child does not exist.\n";
    return nullptr;
}

template <typename T>
T Tree<T>::getValue() {
    return data;
}

template <typename T>
void Tree<T>::setValue(T newData) {
    data = newData;
}

template <typename T>
bool Tree<T>::isLeaf() {
    for(int i = 0; i < maxChildren; i++) { //loop thru children array
        if(children[i] != nullptr) {//if one isnt null, return false
            return false;
        }
    }
    return true; //if all clear
}

template <typename T>
void Tree<T>::preOrder() {
    std::cout << data << ' ';
    for(int i = 0; i < maxChildren; i++) {
        if(children[i] != nullptr) {
            children[i]->preOrder();
        }
    }
}

template <typename T>
void Tree<T>::postOrder() {
    for(int i = 0; i < maxChildren; i++) {
        if(children[i] != nullptr) {
            children[i]->postOrder();
        }
    }
    std::cout << data << ' ';
}

template <typename T>
void Tree<T>::inOrder() {
    if(children[0] != nullptr) {
        children[0]->inOrder();
    }
    std::cout << data << ' ';

    for(int i = 1; i < maxChildren; i++) {
        if(children[i] != nullptr) {
            children[i]->inOrder();
        }
    }
}

template <typename T>
bool Tree<T>::findData(int choice, T findData) {
    bool found = false;

    switch(choice){
        case 1: { //pre order search
            if(data == findData) {
                std::cout << findData << " was found!\n";
                return true;
            }else {
                for(int i = 0; i < maxChildren; i++) {
                    if(children[i] != nullptr && children[i]->findData(1, findData)) {
                        return true;
                    }
                }
            } 
            break;
        }   
        case 2: { //in order search
            if(children[0] != nullptr && children[0]->findData(2, findData)) {
                found = true;
            }else if(data == findData) {
                std::cout << findData << " was found!\n";
                return true;
            }else {
                for(int i = 1; i < maxChildren; i++) {
                    if(children[i] != nullptr && children[i]->findData(2, findData)) {
                        return true;
                    }
                }
            } 
            break;
        }
        case 3: { //post order search
            for(int i = 0; i < maxChildren; i++) {
                if(children[i] != nullptr && children[i]->findData(3, findData)) {
                    found = true;
                    break;
                }
            } 
            if(!found && data == findData) {
                std::cout << findData << " was found!\n";
                return true;
            }
            break;
        }  
        default:
            std::cout << "\nInvalid choice!\n";
            return false;
    }

    return found; 
}

#endif