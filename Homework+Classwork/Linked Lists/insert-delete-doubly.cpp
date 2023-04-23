#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node *prev;
        Node *next;

        //Constructor
        Node() {
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }

        //destructor
        ~Node() {
            cout << "Node with value: " << this->data << " deleted" << endl;
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

//fining the length of total nodes
int findLength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&head, Node*&tail, int data) {
    //if LL is empty
    if(head == NULL && tail == NULL) {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    //if LL is not empty
    else{
        //step 1 create a new Node
        Node *newNode = new Node(data);
        //step 2 point new node next pointer to head
        newNode->next = head;
        //step 3 point head prev pointer to new node
        head->prev = newNode;
        //step 4 update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node*&tail, int data) {
    //if LL is empty
    if(head == NULL && tail == NULL) {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    //if LL is not empty
    else{
        //step 1 create a new Node
        Node *newNode = new Node(data);
        //step 2 point tail next to newNode
        tail->next = newNode;
        //step 3 point newNode prev pointer to tail
        newNode->prev = tail;
        //step 4 update tail
        tail = newNode;
    }
}

void insertAtPosition(int position, int data, Node *&head, Node *&tail) {
    //if LL is empty
     if(head == NULL && tail == NULL) {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    //if LL is not empty 
    //head insert
    if(position == 1) {
        insertAtHead(head, tail, data);
        return;
    }
    //tail insert
    int len = findLength(head);
    if(position > len) {
        insertAtTail(head, tail, data);
        return;
    }
    //any different position insert i.e middle
    //step 1 find prev and curr node
    int i = 1;
    Node *prevNode = head;
    while(i<position-1) {
        prevNode = prevNode->next;
        i++;
    }
    Node *curr = prevNode->next;

    //step 2 create new node
    Node *newNode = new Node(data);

    //step 3
    prevNode->next = newNode;
    newNode->prev = prevNode;
    curr->prev = newNode;
    newNode->next = curr;

}

void deleteFromPos(int position, Node *&head, Node *&tail) {
    if(head == NULL && tail == NULL) {
        //we cant delete anything
        cout << "Cannot delete Doubly LL is empty " <<endl;
        return;
    }
    //if single node
    if(head->next == NULL) {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete(temp);
        return;
    }
    int len = findLength(head);
    if(position > len) {
        cout << "Please give valid position " <<endl;
    }
    //delete the first node
    if(position == 1) {
        //step1 create temp node
        Node *temp =head;
        //step 2
        head = head->next;
        //step 3
        head->prev = NULL;
        //step 4
        temp->next = NULL;
        //STEP 5
        delete(temp); //single node can be deleted
        return;
    }
    if(position == len) {
        //step 1
        Node*temp = tail;
        //step 2
        tail = tail->prev;
        //step 3
        temp->prev = NULL;
        //step 4
        tail->next = NULL;
        //step 5
        delete(temp);
        return;
    }
    //delete from position
    //step 1 find left, right and curr
    //left
    int i=1;
    Node *left = head;
    while(i<position-1) {
        left = left->next;
        i++;
    }
    //curr
    Node *curr = left->next;
    //right
    Node *right = curr->next;
    //step 2
    left->next = right;
    //step 3
    right->prev = left;
    //step 4
    curr->prev = NULL;
    //step 5
    curr->next = NULL;
    //step 6
    delete(curr);

}

int main() {
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    //doubly linked list connected the single node with its prev and next node
    first->next =second;
     
    second->next =third;
    second->prev = first;

    third->prev = second;


    // print(first);
    // cout<<endl;

    insertAtHead(head, tail, 101);
    // print(head);
    // cout<<endl;

    insertAtTail(head, tail, 43);
    // print(head);
    // cout<<endl;

    insertAtPosition(5, 28, head, tail);
    print(head);
    cout<<endl;

    deleteFromPos(3,head,tail);
    print(head);

}