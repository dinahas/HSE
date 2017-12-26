#ifndef TREE_H
#define TREE_H

#include "book.h"
#include "node.h"
#include "storybook.h"
#include "QString"
#include "QDebug"


class Tree
{
public:
    Tree();
    Tree(const Tree &tree);
    Base* find(QString book_name) const;
    void keyInsert(const Book &book);
    void keyInsert(const Storybook &book);
    void keyDelete(QString book);
    int size();
    bool isEmpty();
    void save(QString filename);
    void load(QString filename);
    QString nameGet();
    Node* getRoot();
    Node* getChild(Node* rt);
    Node* getNext(Node *n);

private:
    Node* findRoot(Node *root, QString book_name) const;
    Node* srl(Node* p1);
    Node* drl(Node* p1);
    Node* srr(Node* p1);
    Node* drr(Node* p1);
    Node* nodecopy(Node* root);
    void deleteOne(Node *temp);
    void insert(Base* book, QString name);
    int bsheight(Node* temp);
    int max(int,int);
    Node* root;
    int count = 0;
};

#endif // TREE_H
