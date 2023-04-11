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

//head insertion of nodes
void insertAtHead(Node *&head, int data) { //by reference bcz we want to make changes in original ll no copy
    //step1 create node
    Node *newNode = new Node(data);
    //step2 newNode next point to head
    newNode->next = head;
    //step3 update head as new node
    head = newNode;
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
    Node *head = NULL; //what if head is null
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);

    print(head);
}