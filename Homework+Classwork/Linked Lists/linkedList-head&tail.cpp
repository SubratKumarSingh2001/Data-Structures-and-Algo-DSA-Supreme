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

void insertAtHead(Node* &head, Node* &tail, int data) { //by reference bcz we want to make changes in original ll no copy
    //when linked list is empty
    if(head == NULL && tail == NULL) {
        //create a node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    //when linked list is not empty 
    else {
        //step1 create node
        Node *newNode = new Node(data);
        //step2 newNode next point to head
        newNode->next = head;
        //step3 update head as new node
        head = newNode;
    }
}

//tail insertion of nodes
void insertAtTail(Node* &head, Node* &tail, int data) { //by reference bcz we want to make changes in original ll no copy
    //when linked list is empty
    if(head == NULL && tail == NULL) {
        //create a node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    //when linked list is not empty 
    else {
        //step1 create node
        Node *newNode = new Node(data);
        //tail next node point to new Node
        tail->next = newNode;
        //step3 update tail as new node
        tail = newNode;
    }
}

//print the nodes
void print(Node *head) {
    Node *temp = head; 
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    //single node with data is 10 and next pointer is pointed to NULL
    Node *head = NULL;  //what is head is null
    Node *tail = NULL; //what if tail is null
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtTail(head, tail, 33);

    print(head);
}