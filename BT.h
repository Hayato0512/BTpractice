#ifndef BT_H
#define BT_H
#include "BTNode.h"
#pragma once

class BT
{
public:
    BT(int x);
    ~BT();
    bool add_to_left(int d, int nd, BTNode* root);
    bool add_to_right(int d, int nd, BTNode* root);
    void printRoot();
    void printWholeTree(BTNode* root);
    BTNode* root;
private:
    
};

#endif