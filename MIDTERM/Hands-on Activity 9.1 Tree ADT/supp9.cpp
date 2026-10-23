#include <iostream>
#include "Tree.h"

int main() {
    Tree<char>* root = new Tree<char>('A');

    root->insert('B');
    root->insert('C');
    root->insert('D');
    root->insert('E');
    root->insert('F');
    root->insert('G');

    root->getChild('D')->insert('H');

    root->getChild('E')->insert('I');
    root->getChild('E')->insert('J');

    root->getChild('F')->insert('K');
    root->getChild('F')->insert('L');
    root->getChild('F')->insert('M');

    root->getChild('G')->insert('N');

    root->getChild('E')->getChild('J')->insert('P');
    root->getChild('E')->getChild('J')->insert('Q');

    std::cout << "\nPre-Order Traverse\n";
    root->preOrder();
    
    std::cout << "\nPost-Order Traverse\n";
    root->postOrder();

    std::cout << "\nIn-Order Traverse\n";
    root->inOrder();

    std::cout << "\nFinding J\n";
    root->findData(1, 'J');
    std::cout << "\nFinding K\n";
    root->findData(2, 'K');
    std::cout << "\nFinding A\n";
    root->findData(3, 'A');
    
    std::cout << "\nInserting O\n";
    root->getChild('G')->insert('O');
    std::cout << "\nFinding O\n";
    root->findData(1, 'O');
    

    return 0;
}