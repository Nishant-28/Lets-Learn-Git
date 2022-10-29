#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        // memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d){
    // new node create
    Node *temp = new Node(d);
    tail->next=temp;
    tail=tail->next;
}

void InsertAtMiddle(Node* &tail,Node* &head, int position, int d){
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int count =1;

    while(count<position-1){
        temp=temp->next;
        count++;
    }

    // interting at Last position
    if(temp->next == NULL){
        InsertAtTail(tail,d);
        return;
    }
    // creating a node for 'd'
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head){

    // deleting first node or start node
    if(position==1){
        Node* temp = head;
        head = head->next;
        // memory free krna hoga starting node ka
        temp->next=NULL;
        
    }else{
        //deleting any middle or last node
        Node* curr = head; //current node "crr"
        Node* prev = NULL;

        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    // created a new node
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    // head is pointed to node1
    Node *head = node1;
    Node *tail = node1;


    // print(head);
    // print(node1);
    // InsertAtHead(head, 12);
    // print(head);
    // InsertAtHead(head, 14);
    // print(head);


    print(head);
    InsertAtTail(tail, 9);
    print(head);
    InsertAtTail(tail, 7);
    print(head);

    InsertAtMiddle(tail, head, 4, 2);
    print(head);

    // cout << "head = " << head->data << endl;
    // cout << "tail = " << tail->data << endl;

    deleteNode(4,head);
    print(head);

    // cout << "head = " << head->data << endl;
    // cout << "tail = " << tail->data << endl;
    
    return 0;
}