#ifndef BT_H
#define BT_H
#include "BTNode.h"
#pragma once

class BT
{
public:
    BT(int x);
    BT(BT& oldBT);
    ~BT();
    BTNode* copy_BT(BTNode* newRoot, BTNode* oldRoot);
    bool add_to_left(int d, int nd, BTNode* root);
    bool add_to_right(int d, int nd, BTNode* root);
    void printRoot();
    void printWholeTree(BTNode* root);
    void insert(int x,BTNode* root);
    BTNode* root;
    int elementCount;
    int getElementCount();
    void printHello();
    void remove(int x , BTNode* root);
private:
    void connectParentAndLeftChild(BTNode* ptrToParent, BTNode* ptrToLeftChild);
    void bringPredecessorToTop(BTNode* predecessor, BTNode* TopNode, BTNode*PredecessorParent);
    void bringPredecessorToTopAfterConnectLeftChildAndParent(BTNode* predecessor, BTNode* TopNode);
    bool hasLeftChild(BTNode* current);
    bool hasOnlyLeftChild(BTNode* root);
    bool hasOnlyRightChild(BTNode* root);
    bool isLeaf(BTNode* root);
    bool isLeftChild(BTNode* root);
    bool isRightChild(BTNode* root);
    bool hasBothChild(BTNode* root);
    bool isTopOfTheTree(BTNode* root);
    bool isNotTopOfTheTree(BTNode* root);
};

#endif


