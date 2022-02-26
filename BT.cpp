#include "BT.h"
#include <iostream>
using namespace std;
BT::BT(int x)
{
    BTNode* newNode = new BTNode;
    root = newNode;
    root->data = x;
    elementCount = 1;


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
        elementCount++;
        return true;
    }
    else{
        bool l = add_to_left(d, nd, root->leftChild);
        bool r = add_to_left(d, nd, root->rightChild);
        return l | r;
    }
    
    return false;

}
bool BT::add_to_right(int d, int nd, BTNode* root){
     if(root==NULL){
        return false;
    }
    if(root->data == d){
        BTNode* newNode = new BTNode;
        newNode->data = nd;
        root->rightChild = newNode;
        newNode->parent = root;
        elementCount++;
        return true;
    }
    else{
        bool l = add_to_right(d, nd, root->leftChild);
        bool r = add_to_right(d, nd, root->rightChild);
        return l | r;
    }
    
    return false;
}

void BT::printRoot(){
    cout<<root->data<<endl;
}

void BT::printWholeTree(BTNode* root){
    if(root==NULL)
        return;
    
    printWholeTree(root->leftChild);
    cout<<root->data<<endl;
    printWholeTree(root->rightChild);
}

void BT::insert(int x,BTNode* root){
    if(root==NULL){
        BTNode* newNode = new BTNode;
        root = newNode;
        root->data = x;
        elementCount++;
        return ;
    }
    else{
        if(x<=root->data){
            if(root->leftChild == NULL){
                BTNode* newNode = new BTNode;
                newNode->data = x;
                newNode->parent = root;
                root->leftChild = newNode;
                elementCount++;
            }
            else{
                insert(x, root->leftChild);
            }
        }
        else{
            if(root->rightChild==NULL){
                BTNode* newNode = new BTNode;
                newNode->data = x;
                newNode->parent = root;
                root->rightChild = newNode;
                elementCount++;
            }
            else{
            insert(x, root->rightChild);
            }
        }
    }
}

int BT::getElementCount(){
    return elementCount;
}

void BT::printHello(){
     
    cout<<"Hello people take a break;"<<endl;
}

void BT::remove(int x, BTNode* root){
    if(root==NULL){
        return;
    }

    if(x!=root->data){
        remove(x, root->leftChild);
        remove(x, root->rightChild);
        
    }
   
    else{
        if(root->leftChild==NULL && root->rightChild==NULL){//if roof is a leaf,
            if(root == root->parent->leftChild){
                root->parent->leftChild = NULL;
            }
            else{
                root->parent->rightChild = NULL;
            }
            delete root;
            elementCount--;
            return ;

        }

        else if(root->leftChild!=NULL && root->rightChild==NULL){//if it has only leftChild,
            if(root->parent ==NULL){ //if that is the top of the tree,
                root->leftChild->parent = NULL;
                elementCount--;
            }
            else{//if root of sub tree,
                root->leftChild->parent = root->parent;//root->leftchild is root->parent->leftchild
                if(root= root->parent->leftChild){ //if root was leftchild, put children as leftchild of his grampa.
                    root->parent->leftChild = root->leftChild;
                }
                else{//if root was right child, put his children as right child.
                    root->parent->rightChild = root->leftChild;
                }
                delete root;//delete the node.
                elementCount--;//elementCount --
            }
        }
        

        
    }
}