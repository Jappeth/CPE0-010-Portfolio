#include <iostream>
#include "BST.h"


int main() {
    BinarySearchTree<int> root(2); //root node

    root.insert(3);
    root.insert(9);
    root.insert(18);
    root.insert(0);
    root.insert(1);
    root.insert(4);
    root.insert(5);

    std::cout << "\nPre-order: ";
    root.preOrder();
    std::cout << "\nIn-order: ";
    root.inOrder();
    std::cout << "\nPost-order: ";
    root.postOrder();

    return 0;
}