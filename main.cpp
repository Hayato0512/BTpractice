#include "BTNode.h"
#include "BT.h"

#include <iostream>
using namespace std;

int main(){


    BT a(1) ;
    a.printRoot();
    a.add_to_left(1,2,a.root);
    cout<<a.root->leftChild->data<<endl;
}

//g++ -g -o x main.cpp BT.cpp BTNode.cpp