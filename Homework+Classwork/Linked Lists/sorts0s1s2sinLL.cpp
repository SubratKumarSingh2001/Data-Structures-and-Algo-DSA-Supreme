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

void sortZerosOnesTwos(Node* &head) {
    int zeroCount = 0, onesCount = 0, twoCount = 0;
    //it is advised to create temporary node and store head as we dont want to change the original LL
    //step 1 to count no of zeros, ones and twos
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            onesCount++;
        }
        else if(temp->data == 2) {
            twoCount++;
        }
        //once we checked and satisfied with either of any if-else case we have to move temp one node ahead till
        //temp become null
        temp = temp->next;
    }

    //step 2 to fill the LL with 0, 1 and 2 i.e data replacement
    temp = head;
    while(zeroCount) {
        temp->data = 0;
        temp = temp->next;
        zeroCount--;
    }
    while(onesCount) {
        temp->data = 1;
        temp = temp->next;
        onesCount--;
    }
    while(twoCount) {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }
    //TC = O(N) as there is no nested while loop all are independent loop 
    //SC = O(1) as twe have declare 3 different variable but doesn't change with the length of inputs
}

int main() {
    Node *head = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    Node *fifth = new Node(0);
    Node *sixth = new Node(2);
    Node *seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cout<<"Original LL is : " <<endl;
    print(head);
    cout <<endl;

    cout<<"LL after sort is : " <<endl;
    sortZerosOnesTwos(head);
    print(head);

}