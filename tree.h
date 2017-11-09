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
    Book find(QString book_name) const;
    void keyInsert(Book& book);
    void keyDelete(QString book);
    int size();
    bool isEmpty();
    void save(QString filename);
    void load(QString filename);
    QString nameGet();

private:
    Node* findRoot(Node *root, QString book_name) const;
    Node* srl(Node* p1);
    Node* drl(Node* p1);
    Node* srr(Node* p1);
    Node* drr(Node* p1);
    Node* getNext(Node *n);
    Node* nodecopy(Node* root);
    void deleteOne(Node *temp);
    void insert(Book& book, QString name);
    int bsheight(Node* temp);
    int max(int,int);
    Node* root;
    int count = 0;
};

#endif // TREE_H
