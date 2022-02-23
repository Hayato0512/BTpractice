#ifndef BTNODE_H
#define BTNODE_H

#pragma once

class BTNode
{
public:
    BTNode();
    ~BTNode();
    int data;
    BTNode* parent;
    BTNode* leftChild;
    BTNode* rightChild;



private:

};

#endif