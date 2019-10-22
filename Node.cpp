#include "Node.h"
#include<queue>
#include<iostream>
#include<stack>
using namespace std;

Node::Node(int val,Node *p)
{
    value = val;
    parent = p;
    left = nullptr;
    right = nullptr;
}

void Node::set_descendants(Node* l ,Node* r)
{
    left = l;
    right = r;
}
void Node::set_parent(Node *p)
{
    parent = p;
}

void Node::set_value(int val)
{
    value = val;
}
int Node::get_value()
{
    return value;
}

Node::~Node()
{
   cout<<"dest"<<endl;
}

Node* Node::findNode(Node *root,Node *&p,int val)
{

    queue<Node*> coada;
    Node *temp = nullptr; // nodul care urmeaza sa fie sters
    coada.push(root);

    while(!coada.empty()&&root != nullptr)
    {
        coada.pop();
        if(root->left)
            coada.push(root->left);

        if(root->right)
            coada.push(root->right);


        if(root->get_value() == val)
              temp = root;

        root = coada.front();

        if(coada.size() == 1)
            p = root;  // nodul cel mai de jos

    }

   return temp;

}

Node* Node::removeNodes(Node* &node,int val)
{
    Node *q1 = new Node; // nodul de sters
    Node *q2; // cel mai de jos nod

    while(q1 = Node::findNode(node,q2,val))
        {
            if(node->parent == nullptr&&node->left == nullptr&&node->right == nullptr) // cazul in care node = radacina
            {
                node = node->left = node->right;
                delete q1;
                return node;
            }

            q1->set_value(q2->get_value()); // nodul de sters e inlocuit cu nodul cel mai de jos
           // sterg nodul cel mai de jos
           if(q2->parent->left == q2)
                 q2->parent->left = nullptr;
            else
                q2->parent->right = nullptr;
           delete q2;
        }

  return node;
}

void Node::printInOrder(Node*root)
{

    if(root == nullptr)
    {
        cout<<"arborele nu mai are noduri"<<endl;
        return;
    }
    stack<Node*>s;
    Node* curent = root;
    while(!s.empty()||curent!=nullptr)
    {
        while(curent!=nullptr)
        {
            s.push(curent);
            curent = curent->left;
        }
        curent = s.top();
        s.pop();
        cout<<curent->get_value()<<" ";

        curent = curent->right;
    }


}

