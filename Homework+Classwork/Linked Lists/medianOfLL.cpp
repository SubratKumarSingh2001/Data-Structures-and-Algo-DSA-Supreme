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

//print the nodes
void print(Node *head) {
    Node *temp = head; 
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

Node* medianOfLinkedList(Node* &head) {
    //if no node is present
    if(head == NULL) {
        cout << "Middle cant be found as LL is empty " <<endl;
    }
    //if 1 node 
    if(head->next == NULL) {
        return head;
    }
    //if there are more than 1 node
    Node *slow = head;
    Node *fast = head;
    while(slow != NULL && fast != NULL) {
        /*we are not doing fat->next->next for 2 steps bcz what if fast is at last node and fast->next = NULL
        and NULL->next will be error thats why we use once */
        //1st step of fast
        fast = fast->next;
        if(fast != NULL) {
            //then again 2nd step of fast
            fast = fast->next;
            //now fast has taken 2 step i.e move 2 nodes ahead slow 1 node ahead
            slow = slow->next;
        }
    }
    return slow;
}

int main() {
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third; 
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    //print the nodes
    print(head);
    cout<<endl;

    cout<<"Median of Linked List is " << medianOfLinkedList(head)->data <<endl;
}
