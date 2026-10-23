#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree{
    private:
        //key
        T key;
        //pointers
        BinarySearchTree<T>* left;
        BinarySearchTree<T>* right;

    public:
    //constructor
    BinarySearchTree(T value);
    //insert left and right
    void insert(T newData);
    //traversing
    void preOrder();//root>left>right
    void inOrder();//left>root>right
    void postOrder();//left>right>root
    //searching

};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
        key = value;
        left = nullptr;
        right = nullptr;
}

template <typename T>
void BinarySearchTree<T>:: insert(T newData) {
    if(newData < key) { //if value is going to left
        if(left == nullptr) {//check if left is empty
            left = new BinarySearchTree<T>(newData); //insert 
        } else { //if not empty
            left->insert(newData); //recursive insert into the left
        }
    }else if(newData > key) { //if value is going to right
        if(right == nullptr) { //same idea to left, but on the right
            right = new BinarySearchTree<T>(newData);
        }else {
            right->insert(newData);
        }
    }else { //if equal
        //create new node
        BinarySearchTree <T> *newChild = new BinarySearchTree<T>(newData);
        //move existing node below new node
        newChild->left = left;
        //point parent to new node
        left = newChild;
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {
        std::cout << key << ' '; //print key

        if(left != nullptr) { //recurse on left until there's no left
            left->preOrder();
        }

        if(right != nullptr) {//check right if left is done
            right->preOrder();
        }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {
    if(left != nullptr) { //recurse to the left until left is null
        left->inOrder();
    }

    std::cout << key << ' ';

    if(right != nullptr) {
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder() {
    if(left != nullptr) { //recurse to the left until left is null
        left->postOrder();
    }

    if(right != nullptr) {
        right->postOrder();
    }
    
    std::cout << key << ' ';
}

#endif