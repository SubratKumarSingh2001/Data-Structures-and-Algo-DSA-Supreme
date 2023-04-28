#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *next;

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

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* reverseTheLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}


Node* addTwoNodes(Node* &head1, Node* &head2) {
    //step 1 reverse the both LL
    head1 = reverseTheLL(head1);
    head2 = reverseTheLL(head2);

    //create an ans node which will store the add of 2 number
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    //we will take a carry variable of int type as we add two numbers there might be 2 digit no to take carry
    int carry = 0;

    //step 2 add both linked list
    //when both the LL is not empty
    while(head1 != NULL && head2 != NULL) {
        int sum = carry + head1->data + head2->data;
        //as we need to find the single digit from 2 digit number when we add 2 number
        int digit = sum%10;
        carry = sum/10;

        //now we need to create a new node to add digit in it
        Node *newNode = new Node(digit);

        //check whether the ans node is null or not if yes the newNode will be first and node else join with tail
        if(ansHead == NULL) {
            //newnode will become first and node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }
        //move head of both LL ahead
        head1 = head1->next;
        head2 = head2->next;
    }

    //what is head2 become null but head1 still consists of nodes
    while(head1 != NULL) {
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    //what is head1 become null nut head2 still consists of nodes
      while(head2 != NULL) {
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    //what if head1 and head2 become null but we still consists of carry
    while(carry != 0) {
        int sum = carry;
        int digit = sum%!0;
        carry = sum/10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }
    
    //step 3 reverse final ans linked list
    /* as we have now final ans linked list we need to just reverse it by passing it head */
    ansHead = reverseTheLL(ansHead);
    return ansHead;
}

int main() {
    Node *head1 = new Node(2);
    Node *second1 = new Node(4);
    Node *third1 = new Node(6);
    Node *fourth1 = new Node(1);
    Node *fifth1 = new Node(2);
    head1->next = second1;
    second1->next -third1;
    third1->next = fourth1;
    fourth1->next = fifth1;

    Node *head2 = new Node(4);
    Node *second2 = new Node(5);
    Node *third2 = new Node(6);
    head2->next = second2;
    second2->next = third2;

    Node *ans = addTwoNodes(head1, head2);
    print(ans);
}