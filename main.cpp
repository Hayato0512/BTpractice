#include "BTNode.h"
#include "BT.h"

#include <iostream>
using namespace std;

int main(){


    BT* a = new BT(5);
    //a->insert(5, a->root);
    a->insert(15, a->root);
    a->insert(11, a->root);
    a->insert(12, a->root);
    //a->insert(3, a->root);
    a->insert(13, a->root);
    a->insert(14, a->root);
    a->insert(16, a->root);
    a->insert(9, a->root);
    //a->printWholeTree(a->root);
/*
    a->remove(15, a->root);
a->printWholeTree(a->root);
cout<<"========================"<<endl;
 a->remove(16, a->root);
a->printWholeTree(a->root);
 a->remove(14, a->root);
a->printWholeTree(a->root);
a->remove(11, a->root);
a->printWholeTree(a->root);
*/
   // BT b((*a));
    //b.printWholeTree(b.root);
    // a.insert(2, a.root);
    // a.insert(1, a.root);
    // a.insert(3, a.root);
    // a.insert(6, a.root);
    // a.insert(7, a.root);
    // a.insert(11, a.root);
    // a.insert(9, a.root);
    
    // a.insert(4, a.root);

    // a.insert(3, a.root);

    

    //a.printRoot();
    //a.add_to_left(1,2,a.root);
    //cout<<a.root->leftChild->data<<endl;
    //a.add_to_right(1,3,a.root);
   // cout<<a.root->rightChild->data<<endl;
    //a.printWholeTree(a.root);
    //a.getElementCount();
    //a.printHello();
    //a.remove(4, a.root);
    //a.printWholeTree(a.root);
}

//g++ -g -o x main.cpp BT.cpp BTNode.cpp