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

Node* merge(Node* &head1, Node* &head2) {
    Node* ans = new Node(-1);
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* temp3 = ans;
    while(temp1 && temp2) {
        if(temp1->val < temp2->val) {
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

Node* findMid(Node* &head) {
    Node* slow = head;
    Node* fast = head->next; //because for even we get second mid but want 1st mid
    while(fast && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* sortList(Node* &head) {
    //Brute Force take all elements and put it in array and sort it
    //TC: O(n)+O(n*logn)+O(n) = O(n*logn) where n is no.of nodes in Linked List
    //SC: O(n)+O(n) = O(2n) = O(n) 
    //single and empty linked list
    // if(head == NULL || head->next == NULL) return head;

    // Node* temp = head;
    // vector<int> ans;
    // while(temp) {
    //     ans.push_back(temp->val);
    //     temp = temp->next;
    // }
    // //now apply the sort 
    // sort(ans.begin(), ans.end());
    // Node* newHead = new Node(-1);
    // temp = newHead;
    // for(int i=0; i<ans.size(); i++) {
    //     Node* newNode = new Node(ans[i]);
    //     temp->next = newNode;
    //     temp = temp->next;
    // }

    // return newHead->next;

    //Optimal Solution using merge sort
    //TC: O(n*logn), SC: O(1)
    //base case when we have single node or no node i.e head is null
    if(head == NULL || head->next == NULL) return head;

    //now we will find the mind using Tortoise-Hare Algo
    Node* mid = findMid(head);
    //right divide the linked list
    Node* rightHead = sortList(mid->next);
    //separate both the linked list
    mid->next = NULL;
    //left divide the linked list
    Node* leftHead = sortList(head);

    //now we will merge the sorted linked list
    Node* newHead = merge(leftHead, rightHead);

    return newHead;
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
    sortList(head);
    displayLL(head);
}