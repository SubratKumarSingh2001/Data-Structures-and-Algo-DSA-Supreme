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

void removeDuplicates(Node* &head) {
    //if LL is empty
    if(head == NULL) {
        cout << "LL is empty " <<endl;
        return;
    }
    //if we have single node
    if(head->next == NULL) {
        cout << "Single node cant find the duplicate " <<endl;
        return;
    }

    //generic if we have more than 1 node
    Node *curr = head;
    while(curr != NULL) {
        //check whether the curr node data is equal to curr->next node data
        /*
        here we can see that curr will not be null acc to the while loop but there is possibility of curr->next
        maybe null if we are at last node. So we need to check that curr->next should not be null
        */
        if((curr->next != NULL) && (curr->data == curr->next->data)) {
            //create a temp node to store curr->next 
            Node *temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else {
            //move curr node 1 step when curr and curr->next data are not same
            curr = curr->next;
        }
    }
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(3);
    Node *fifth = new Node(4);
    Node *sixth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Original LL with duplicates " <<endl;
    print(head);
    cout <<endl;

    cout << "LL after removing duplicates " <<endl;
    removeDuplicates(head); 
    print(head);

}