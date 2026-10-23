#include <iostream>
#include "doubly_ll.h"

int main(){
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    //traversal
    std::cout<<"\nTesting the DLL Traversal";
    dllTraverse(head);

    //insert head
    dllInsertHead('X', head);
    dllTraverse(head);

    //insert at tail
    dllInsertEnd('Y', head);
    dllTraverse(head);

    //gen insert
    dllGeneralInsert('O', head->next);
    dllTraverse(head);

    //deletes
    dllDeleteNode('O', head);
    dllTraverse(head);

    dllDeleteNode('Y', head);
    dllTraverse(head);

    dllDeleteNode('X', head);
    dllTraverse(head);

    return 0;
}