#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        
    }
};

int main()
{
    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head is pointed to node1
    Node *head = node1;
    // Node *tail = node1;
    return 0;
}