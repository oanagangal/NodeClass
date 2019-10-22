#include <iostream>
#include "Node.h"

using namespace std;



int main()
{
    Node *n1 = new Node(5);
    Node *n2 = new Node(5,n1);
    Node *n3 = new Node(5,n1);
    Node *n4 = new Node(5,n2);
    Node *n6 = new Node(5,n3);

    n3->set_descendants(0,n6);
    n2->set_descendants(n4,0);
    n1->set_descendants(n2,n3);
    Node::printInOrder(n1);
    Node::removeNodes(n1,5);

    Node::printInOrder(n1);



    return 0;
}
