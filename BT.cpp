#include "BT.h"
#include <iostream>
using namespace std;
BT::BT(int x)
{
    BTNode* newNode = new BTNode;
    root = newNode;
    root->data = x;


}

BT::~BT()
{

}

bool BT::add_to_left(int d, int nd, BTNode* root){
    if(root==NULL){
        return false;
    }
    if(root->data == d){
        BTNode* newNode = new BTNode;
        newNode->data = nd;
        root->leftChild = newNode;
        newNode->parent = root;
        return true;
    }
    else{
        bool l = add_to_left(d, nd, root->leftChild);
        bool r = add_to_left(d, nd, root->rightChild);
        return l | r;
    }
    
    return false;

}
//bool add_to_right(int d, int nd, BTNode* root);

void BT::printRoot(){
    cout<<root->data<<endl;
}