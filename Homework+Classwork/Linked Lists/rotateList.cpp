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

int length(Node* &head) {
    Node* temp = head;
    int len = 0;
    while(temp) {
        len++;
        temp = temp->next;
    }
    return len;
}
Node* rotateRight(Node* &head, int k) {
    //ONE WAY TO DO THIS
    //TC: O(n)+O(n)+O(n) = O(n), SC: O(1)
    // if no node present and single node
    if (head == NULL || head->next == NULL || k==0) {
        return head;
    }

    int len = length(head);
    if(k == len) return head;
    k = k % len;
    ListNode* slow = head;
    for(int i=0; i<len-k-1; i++) {
        slow = slow->next;
    }
    ListNode* fast = slow->next;
    ListNode* temp = fast;
    if(slow->next != NULL) {
        slow->next = NULL;
    }
    else {
        return head;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head = fast;

    // return head;

    //ANOTHER WAY TO DO THIS QUESTION 
    //TC: O(n)+O(n)+O(n) = O(n), SC: O(1)
    if(head == NULL || head->next == NULL || k==0) {
        return head;
    }
    Node* temp = head;
    int len=1;
    while(temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    
    k = k % len;
    int end = len-k-1;
    Node* ptr = head;

    while(end--) {
        ptr = ptr->next;
    }

    Node* ptrNext = ptr->next;
    if(ptrNext) {
        ptr->next = NULL;
        temp->next = head;
        head = ptrNext;
    }
    return head;
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
    cout<<"Enter the value of k : "; cin>>k;
    rotateRight(head, k);
    displayLL(head);
}