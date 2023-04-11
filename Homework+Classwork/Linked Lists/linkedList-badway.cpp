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

//print the nodes
void print(Node *first) {
    Node *temp = first; 
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third; 
    third->next = fourth;
    fourth->next = fifth;

    //print the nodes
    print(first);
}