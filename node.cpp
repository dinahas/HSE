#include "node.h"
#include "book.h"

using namespace std;

/*Node::Node()
{
    book = nullptr;
    //left = new Node(this);
    //right = new Node(this);
    key = NULL;
    height = 0;
}*/

Node::Node(){
    //book = data;
    left = new Node(this);
    right = new Node(this);
    key = "";
    height = 0;
    isLeaf = false;

}
Node::Node(Node *a){
    curr = a;
    left = right = NULL;
    key = "";
    height = 0;
    isLeaf =true;
}

Node::~Node(){

}
