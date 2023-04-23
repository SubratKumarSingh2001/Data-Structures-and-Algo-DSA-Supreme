#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *prev;
        Node *next;

        //Constructor
        Node() {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

//print the nodes
void print(Node *head) {
    Node *temp = head; 
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp = temp->next;
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

int main() {
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    //doubly linked list connected the single node with its prev and next node
    first->next =second;
     
    second->next =third;
    second->prev = first;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    print(first);

}