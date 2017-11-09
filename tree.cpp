#include "tree.h"
#include "node.h"
#include <QFile>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>

Tree::Tree()
{
    root = NULL;
    //heigh = 0;
    qDebug() <<"default";
}

/*Tree::Tree(const Tree &tree){
    //tree_size = 0;
    root = NULL;
    Node* temp = tree.root;
    while(temp->left&&!temp->left->isLeaf) temp = temp->left;
    while(temp&&!temp->isLeaf)
    {
        keyInsert(temp->book);
        temp = getNext(temp);
    }
        qDebug() <<"constructor";
    //}
}*/

Tree::Tree(Tree const &tree){
    Node* copy = nodecopy(tree.root);
}

Node* Tree::nodecopy(Node* root){
    Node* temp;
    if (root == NULL)
    {
        return root;
    }
    else
    {
        temp = new Node;
        temp->book = root->book;
        temp->left = nodecopy(root->left);
        temp->right = nodecopy(root->right);
        return temp;
    }
}

void Tree::load(QString filename){
    QFile file (filename);
    file.open(QFile::ReadOnly);
    QString val = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonArray array(doc.array());
    foreach (auto obj, array) {
        auto name = obj.toObject()["name"].toString();
        auto author = obj.toObject()["author"].toString();
        auto genre = obj.toObject()["genre"].toString();
        auto descr = obj.toObject()["descr"].toString();
        int year = obj.toObject()["year"].toString().toInt();
        Book book(author, name, genre, descr, year);
        keyInsert(book);

    }
}

void Tree::save(QString filename) {
    QJsonArray array;
    if (!isEmpty()) {
        Node* temp = root;
        while (temp != NULL) {
            QJsonObject toWrite;
            temp->book.toJsonObject(toWrite);
            array.push_back(QJsonValue (toWrite));
            temp = getNext(temp);
        }
    }
    if (!array.empty()) {
        QJsonDocument doc (array);
        QFile file (filename);
        file.open(QFile::WriteOnly);
        file.write(doc.toJson());
        file.close();
    }
}

Book Tree::find(QString name) const{
    Node* temp = findRoot(root, name);
    Book tempbook;
    //return temp==NULL ? temp->book : tempbook;
    if (temp == NULL)
        return tempbook;
    else
        return temp->book;
}

Node* Tree::findRoot(Node* _root, QString name) const {
    if(_root != NULL){
        if(_root->key == name) return _root;
        else
        {
            if(name < _root->key) return findRoot(_root->left, name);
            else return findRoot(_root->right, name);
            //return NULL;
        }
    }
        else return NULL;
}

void Tree::deleteOne(Node *root){
    Node* d;
    if ((!root->isLeaf) && (!root->isLeaf))
        {
            d=root;
            delete d;
            root=NULL;
        }
        else if (root->left == NULL)
        {
            d=root;
            delete d;
            root=root->right;
        }
        else if (root->right == NULL)
        {
            d=root;
            root=root->left;
            delete d;
        }
}

void Tree::keyDelete(QString name)
{
    Node* delNode = NULL;
    delNode = findRoot(root, name);
    if(delNode){
        deleteOne(delNode);
        count--;
        qDebug() <<"deteted";
    }
    else qDebug() <<"No key";
}

void Tree::keyInsert(Book& book)
{
    QString name = book.getName();
    Node* nex = findRoot(root, name);
    if(!nex){
        insert(book, name);
        count++;
    }
    qDebug() <<"Work";
    qDebug() <<(bsheight(root->left) + bsheight(root->right) + 1);

}

void Tree::insert(Book& book, QString name){
    Node* temp = new Node;
    temp->book = book;
    temp->key = name;
    if (!root) root = temp;
    else{
        Node* r = root;
        bool f = true;
        while (!(r->left->isLeaf&&r->right->isLeaf)&&f) {
        if(name < temp->key){
            if (!(r->left->isLeaf && r->right->isLeaf)&&f)
            {
                r = r->left;
                if ((bsheight(r->left) - bsheight(r->right))==2){
                    if (name < r->left->key){
                        r = srl(r);
                    }
                    else{
                        r = drl(r);
                    }
                }
            else
                f = false;
            }
        }
        else{
            if(!r->right->isLeaf){
                r = r->right;
                if((bsheight(r->right) - bsheight(r->left))==2)
                    if (name > r->right->key){
                        r = srr(r);
                    }
                    else{
                        r= drr(r);
                    }
            }
            else f = false;

        }
        }
        int m,n,d;
        m=bsheight(r->left);
        n=bsheight(r->right);
        d=max(m,n);
        r->height = d + 1;
        //root = r;
        temp->curr=r;
        if(temp->key>=r->key) r->right = temp;
        else r->left = temp;
    }
}

Tree::bsheight(Node *temp){
    int t;
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        t = temp->height;
        return t;
    }
    qDebug() << "height";
}

Node* Tree:: srl(Node* p1)
{
    Node* p2 = new Node;
    p2 = p1->curr->left;
    p1->curr->left = p2->curr->right;
    p2->curr->right = p1->curr;
    p1->curr->height = max(bsheight(p1->curr->left),bsheight(p1->curr->right)) + 1;
    p2->curr->height = max(bsheight(p2->curr->left),p1->curr->height) + 1;
    return p2->curr;
}

Node* Tree:: drl(Node* p1)
{
    p1->left=srr(p1->left);
    return srl(p1);
}

Node* Tree:: srr(Node* p1)
{
    Node* p2 = new Node;
    p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;
    p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
    p2->height = max(p1->height,bsheight(p2->right)) + 1;
    return p2;
}

Node* Tree::drr(Node* p1)
{
    p1->right = srl(p1->right);
    return srr(p1);
}

int Tree::max(int value1, int value2)
{
    return ((value1 > value2) ? value1 : value2);
}

int Tree::size()
{
    return count;
}

bool Tree::isEmpty()
{
    if(root) return false;
    else return true;
    //qDebug() << "isEmpty";
}

Node* Tree::getNext(Node *n)
{
    Node* next = n;
    if(!n->right->isLeaf)
    {
        next = next->right;
        while(!next->left->isLeaf) next = next->left;
        return next;
    }
    else if(n->curr->left==n) return next->curr;
    //else if(n->curr->curr&&n->curr->curr->left==n->curr) return next->curr;
    else return NULL;
}

QString Tree::nameGet()
{
    Node* r = root;
    QString names = NULL;
    r = getNext(r);
    while (r){
        names = names + r->key + " ";
        r = getNext(r);
    }
    return names;
}
