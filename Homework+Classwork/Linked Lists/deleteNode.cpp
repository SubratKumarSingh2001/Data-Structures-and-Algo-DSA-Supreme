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

        //destructor
        ~Node() {
            cout << "Node with value: " << this->data << " deleted" << endl;
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

//fining the length of total nodes
int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data) {
    //find the position of previous and current node
    //check linked list is empty or not
    if(head == NULL && tail == NULL) {
        //create a node
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // LL is not empty
    //if I want to place node at start i.e at head ,position=0
    if(position == 0) {
        //call insert at head one
        insertAtHead(head, tail, data);
        return;
    } 
    //if I want to place node at end i.e at tail, position>=len
    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    //step 1 find the position of prev and current node
    //we find prev node
    int i=1;
    Node *prev = head; 
    while(i<position) {
        prev = prev->next;
        i++;
    }
    //we find curr node
    Node *curr = prev->next;

    //step 2 create a new node
    Node *newNode = new Node(data);

    //step 3 
    newNode->next = curr;

    //step 4
    prev->next = newNode;

}

void deleteNode(int position, Node* &head, Node* &tail) {
    //if we have no node
    if(head == NULL) {
        cout << "Cannot delete a Node Linked List is empty " <<endl;
    }
    //if you want to delete first node i.e head
    if(position == 1) {
        //step 1 create temp node
        Node *temp = head;
        //step 2 update head
        head = head->next;
        //step 3 temp next is null
        temp->next = NULL;
        //step 4 delete node
        delete(temp);
    }

    //if you want to delete last node i.e tail
    int len = findLength(head);
    if(position == len) {
        //step 1 find the previous node 
        int i=1;
        Node *prev = head;
        while(i<position-1) {
            prev = prev->next;
            i++;
        }
        //step 2 
        prev->next = NULL;
        //step 3 temp node create
        Node *temp = tail;
        //step 4
        tail = prev;
        //step 5
        delete(temp);
    }

    //if we want to delete node from any position leaving last and first
    //step 1 find prev and curr
    int i=2;
    Node *prev = head;
    while(i<position) {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    //step 2 //previous ka pointer curr k next s jod do 
    prev->next = curr->next;
    //step 3 // curr the pointer ko null kr do taki single node ho jaye
    curr->next = NULL;
    //step 4 //delete kr do
    delete(curr);
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
    Node *head = NULL;  //what is head is null
    Node *tail = NULL; //what if tail is null
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtTail(head, tail, 33);
    cout << "Nodes before insertion at any specific positions " <<endl;
    print(head);
    cout<<endl;
    // cout<<endl;
    // cout<< "Nodes after insertion at any specific position " <<endl;
    // int position;
    // cout << "Enter the position you want to place a Node : ";cin>>position;
    // insertAtPosition(position, head, tail, 101);
    // print(head);

    //delete a node
    deleteNode(5, head, tail);
    print(head);
    cout<<endl;

}