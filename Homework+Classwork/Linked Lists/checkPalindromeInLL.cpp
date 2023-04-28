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

Node* reverseTheLL(Node* &head) {
    // we must have prev, curr and forward node
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; //head of reverse node
}

bool checkPalindrome(Node* &head) {
    //if LL is empty
    if(head == NULL) {
        cout << "LL is empty " <<endl;
        return false;
    }
    //if there is only single node
    if(head->next == NULL) {
        //single node is always a palindrome
        return true;
    }

    //generic case when we have more than 1 nodes
    //step 1 find the middle of LL with slow and fast pointer
    //head->next bcz for even no of nodes we have two middle but if we want first middle than head-next
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL) {
        fast = fast->next; //fast wont take 2 step at a time bcz fast could be at last node i.e null->null error
        if(fast != NULL) {
            //2nd step of fast as fast is not NULL
            fast = fast->next;
            slow = slow->next;
        }
    }
    //basically now slow pointer will hold the middle node of LL

    //step 2 reverse the LL after the middle node
    /*
    we have pass the slow->next as reverse func parameter bcz we want to reverse the LL after the middle node
    and middle node is pointed by pointer slow. therefore the next node after middle node will be slow->next
    which is basically the head of reverse node
    */
    Node *reverseLLHead = reverseTheLL(slow->next);

    //step 3 is comparing 2 LL one left of middle node and another right of middle node
    Node *temp1 = head; //head of LL left to the middle node
    Node *temp2 = reverseLLHead; //head of LL right to the middle node i.e reversed LL

    while(temp2 != NULL) {
        if(temp1->data != temp2->data) {
            //left and right LL data are not equal the LL is not palindrome
            return false;
        }
        else {
            //move temp1 and temp2 one step ahead
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    //when we come out of while loop means data left to middle and data right to middle are same
    return true;
}

int main() {
    Node *head = new Node(10);
    Node *second = new Node(200);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *fifth = new Node(200);
    Node *sixth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome) {
        cout <<"Linked List is a Palindrome " <<endl;
    }
    else {
        cout <<"Linked List is not a Palindrome " <<endl;
    }
}