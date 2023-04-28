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

Node* sortZerosOnesTwos(Node* &head) {
    //empty LL
    if(head == NULL) {
        cout << "LL is empty " <<endl;
        return NULL;
    }
    //1 node
    if(head->next == NULL) {
        return head;
    }

    //if there are more than 1 nodes
    //step 1 create 3 different dummy nodes
    /*
    here we are creating dummy nodes of 0,1 & 2 to attach 0 1 2 data for original LL and form 3 different LL 
    a node must have same head and tail
    */
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    /* step 2 to traverse from original LL and check whether the data is 0 1 or 2 resp. and place them with
    respective dummy node
    */
    Node *curr = head;
    while(curr != NULL ){
        //check whether the data is 0 
        if(curr->data == 0) {
            //then make this node single stand alone to place it with dummy node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //now join the single node with data 0 with dummy node of 0 which we have created above
            zeroTail->next = temp;
            zeroTail = temp; //to move zeroTail one step ahead
        }
        else if(curr->data == 1) {
            //then make this node single stand alone to place it with dummy node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //now join the single node with data 1 with dummy node of 1 which we have created above
            oneTail->next = temp;
            oneTail = temp; //to move oneTail one step ahead
        }
        else if(curr->data == 2) {
            //then make this node single stand alone to place it with dummy node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            //now join the single node with data 2 with dummy node of 2 which we have created above
            twoTail->next = temp;
            twoTail = temp; //to move twoTail one step ahead
        }
    }

    //till now we have 3 different LL of 0, 1 and 2
    /* now we will delete the dummy nodes of 1 and 2 and then join the both nodes later on we will delete the
    dummy node of 0*/
    //to delete dummy 1 node
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    //to delete dummy 2 node
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    //now we have delete the dummy 1 and 2 node now to join the LL
    /*we are checking that oneHead is not null to ensure that data i.e 1 is present */
    if(oneHead != NULL) {
        //join LL containing 0s with LL containing 1
        zeroTail->next = oneHead;
        // we also need to join the LL containing 1s with 2s
        if(twoHead != NULL) { //to ensure that data i.e 2 is present
            oneTail->next = twoHead;
        }
    }
    else {
        //as oneHead is null mean in original LL data consists of 0 and 2
        if(twoHead != NULL) {
            zeroTail->next = twoHead;
        }
    }

    //delete dummy 0 node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    //return the head of modified LL
    return zeroHead;
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
    head = sortZerosOnesTwos(head);
    print(head);

}