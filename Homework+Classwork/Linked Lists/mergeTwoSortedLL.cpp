#include <iostream>
using namespace std;

class Node {
    public : 
        int val;
        Node* next;

        Node() {
            this->val = 0;
            this->next = NULL;
        }
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
};

Node* createNode(int val) {
    Node* newNode = new Node(val);
    newNode->next = NULL;

    return newNode;
}

void createLL(Node* &head, int val) {
    Node* newNode = createNode(val);

    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayLL(Node* &head) { //here head is pass by reference as any changes made will be made at original head pointer 
    Node* temp = head;
    while(temp) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

Node* mergeTwoLists(Node* &head1, Node* &head2) {
    //TC: O(n+m) n and m are length of either linked list , SC: O(1) no extra space
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* ans = new Node(-1);
    Node* temp3 = ans;
    while(temp1 && temp2) {
        if(temp1->val <= temp2->val) {
            temp3->next = temp1;
            temp1 = temp1->next;
        }
        else {
            temp3->next = temp2;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }

    while(temp1) {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    while(temp2) {
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }

    return ans->next;
}

int main() {
    int size1;
    cout<<"Enter the size of first Linked List(no.of linked list element you want) : "; cin>>size1;

    Node* head1 = NULL;
    Node* head2 = NULL;

    int val;
    cout<<"Enter the values of first Linked List you want to insert : ";
    for(int i=0; i<size1; i++) {
        cin>>val;
        createLL(head1, val);
    }

    int size2;
    cout<<"Enter the size of second Linked List(no.of linked list element you want) : "; cin>>size2;

    cout<<"Enter the values of second Linked List you want to insert : ";
    for(int i=0; i<size2; i++) {
        cin>>val;
        createLL(head2, val);
    }
    Node* finalHead = mergeTwoLists(head1, head2);
    displayLL(finalHead);
}