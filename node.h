#ifndef NODE_H
#define NODE_H

#include "book.h"
#include "base.h"
#include "QString"
#include <iostream>
//#include "cstddef"

class Node
{
public:
    //Node();
    //Book book;
    Base* data;
    QString key;
    Node *left, *right, *curr;
    int height;
    bool isLeaf;
    ~Node();
    Node();
    Node(Node *a);
};

#endif // NODE_H
