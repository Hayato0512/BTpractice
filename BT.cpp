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
        if(isLeaf(root)){//if roof is a leaf,
            if(isLeftChild(root)){
                root->parent->leftChild = NULL;
            }
            else{
                root->parent->rightChild = NULL;
            }
            delete root;
            elementCount--;
            return ;

        }

        else if(hasOnlyLeftChild(root)){//if it has only leftChild,
            cout<<"ok, this guy has only left child"<<endl;
            if(root->parent ==NULL){ //if that is the top of the tree,
                cout<<"yes yes this is the top"<<endl;
                root->leftChild->parent = NULL;
                this->root = root->leftChild;
                delete root;

                elementCount--;
            }
            else{//if root of sub tree,
                cout<<"yes this root is a sub tree"<<endl;
                root->leftChild->parent = root->parent;//root->leftchild is root->parent->leftchild
                if(isLeftChild(root)){ //if root was leftchild, put children as leftchild of his grampa.
                    root->parent->leftChild = root->leftChild;
                }
                else{//if root was right child, put his children as right child.
                    root->parent->rightChild = root->leftChild;
                }
                delete root;//delete the node.
                elementCount--;//elementCount --
            }
        }
        else if(hasOnlyRightChild(root)){//if it has only rightChild,
            if(isTopOfTheTree(root)){ //if that is the top of the tree,
                cout<<"yes yes this is the top"<<endl;
    
                this->root = root->rightChild;
                delete root;
                elementCount--;

            }
             else{//if root of sub tree,
                cout<<"yes this root is a sub tree"<<endl;
                root->rightChild->parent = root->parent;//root->leftchild is root->parent->leftchild
                if(isLeftChild(root)){ //if root was leftchild, put children as leftchild of his grampa.
                    root->parent->leftChild = root->rightChild;
                }
                else{//if root was right child, put his children as right child.
                    root->parent->rightChild = root->rightChild;
                }
                delete root;//delete the node.
                elementCount--;//elementCount --
            }
        }
        else if(hasBothChild(root) &&isTopOfTheTree(root)){//if has two child and the top of the tree,
            BTNode* current=NULL;
          
            current = root->leftChild;
            
            while(current->rightChild!=NULL){
                current = current->rightChild;
            }
            BTNode* tmp = current->parent;
            if(current->leftChild!=NULL){//if the current has leftchild, (it doesnot have right child becuase we came all the way down acrross rightCHild)
                current->leftChild->parent = tmp;
                tmp->rightChild = current->leftChild;
            }
            else{//if leaf
                root->leftChild->parent = current;
                root->rightChild->parent = current;
                current->leftChild = root->leftChild;
                current->rightChild = root->rightChild;
                this->root = current;
                tmp->rightChild =NULL;
                elementCount--;
                delete root;
            }
        }
        

        
    }
}

bool BT::hasOnlyLeftChild(BTNode* root){
    return (root->leftChild!=NULL && root->rightChild==NULL);
}
bool BT::hasOnlyRightChild(BTNode* root){
    return (root->leftChild==NULL && root->rightChild!=NULL);
}

bool BT::isLeaf(BTNode* root){
    return (root->leftChild==NULL && root->rightChild==NULL);

}

 bool BT::isLeftChild(BTNode* root){
     return (root == root->parent->leftChild);
 }

 bool BT::isRightChild(BTNode* root){
     return (root == root->parent->rightChild);
 }

 bool BT::hasBothChild(BTNode* root){
    return (root->leftChild!=NULL && root->rightChild!=NULL);
}
bool BT::isTopOfTheTree(BTNode* root){
    return (root->parent ==NULL);
}