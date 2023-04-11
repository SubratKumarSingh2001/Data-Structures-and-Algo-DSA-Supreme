#include <iostream>
using namespace std;

class Node {
    public : 
        int data; //node consists of data of any type, multiple data can be stored
        Node *next; //node consists of pointer which hold the address of next node;
        
        //Constructor
        Node() {
            this->data = 0;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

//tail insertion of nodes
void insertAtTail(Node *&head, Node *&tail, int data) { //by reference bcz we want to make changes in original ll no copy
    //step1 create node
    Node *newNode = new Node(data);
    //when our head and tail node is NULL, means we are creating our first node 
    //when both head and tail are null so we say tail and head our new Node
    if(tail == NULL) {
        head = newNode;
    }
    else {
        //when we have atleast one node i.e head and tail node then this code will work Linked list non empty
        tail->next = newNode;
    }
    //step3 update tail as new node
    tail = newNode;
}

//print the nodes
void print(Node *tail) {
    Node *temp = tail; 
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    //single node with data is 10 and next pointer is pointed to NULL
    Node *head = NULL;  //what is head is null
    Node *tail = NULL; //what if tail is null
    insertAtTail(head, tail, 20);

    print(tail);
}