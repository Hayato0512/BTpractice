#include "BTNode.h"
#include "BT.h"

#include <iostream>
using namespace std;

int main(){


    BT a(5) ;
    a.insert(2, a.root);
    a.insert(8, a.root);
    a.insert(1, a.root);
    a.insert(4, a.root);

    a.insert(3, a.root);

    a.insert(6, a.root);
    a.insert(7, a.root);
    a.insert(11, a.root);
    a.insert(9, a.root);

    //a.printRoot();
    //a.add_to_left(1,2,a.root);
    //cout<<a.root->leftChild->data<<endl;
    //a.add_to_right(1,3,a.root);
   // cout<<a.root->rightChild->data<<endl;
    a.printWholeTree(a.root);
}

//g++ -g -o x main.cpp BT.cpp BTNode.cpp