#ifndef NODE_H
#define NODE_H

using namespace std;


class Node
{
    public:
        Node *parent;
        Node *left;
        Node *right;

        Node(int val = 0,Node *p = 0);
        ~Node();



    static Node* findNode(Node* root,Node*&,int val);

    void set_descendants(Node *l,Node *r);
    void set_parent(Node *p);
    void set_value(int val);
    int get_value();
    static void printInOrder(Node*root);

    static Node* removeNodes(Node* &node,int val);

    private:
        int value;
};

#endif // NODE_H
