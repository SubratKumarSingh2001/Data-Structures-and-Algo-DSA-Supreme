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

int kthNodeEndOfLL(Node* &head, int k) { //pass by reference to make changes in the original code
    Node* fast = head;
    for(int i=0; i<k; i++) {
        //check whether the k is not more than len of ll
        if(fast == NULL) return -1;
        fast = fast->next;
    }
        
    //now use slow ptr to make the node diff of 3 b/w fast and slow ptr
    Node* slow = head;
    while(fast) {
        fast = fast->next;
        slow = slow->next;
    }
        
    return slow->val;
}


int main() {
    int size;
    cout<<"Enter the size (no.of linked list element you want) : "; cin>>size;

    Node* head = NULL;
    int val;
    cout<<"Enter the values you want to insert in linked list : ";
    for(int i=0; i<size; i++) {
        cin>>val;
        createLL(head, val);
    }
    int k;
    cout<<"Enter the value of k (which node you want to print from the last) : "; cin>>k;
    int node = kthNodeEndOfLL(head, k);
    cout<<"The kth node from the end is : " << node << endl;
    
}