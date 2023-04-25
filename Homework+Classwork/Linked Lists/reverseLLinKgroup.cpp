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

int getLength(Node *head) {
    int len = 0;
    Node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* reverseKNodes(Node* &head, int k) {
    //what if LL is empty 
    if(head == NULL) {
        cout << "Linked List is empty " <<endl;
    }
    //what if k is more than length of nodes 
    int len = getLength(head);
    if(k > len) {
        return head;
    }

    //generic case when k <= length of nodes
    //step 1 reverse the k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    /*
    here we have taken count=0 bcz to reverse the k nodes to keep the track that only the k nodes are being
    reversed
    */
    int count = 0;
    
    //count < k as to reverse till k nodes if count > k then the while statement won't run and we have reversed
    //the k nodes
    while(count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++; //to update the count to reverse the k nodes
    }

    //step 2 to check whether forward/upcoming nodes can be reversed in k groups or not
    if(forward != NULL) {
        /*
        here in recursion we have pass forward as head because for recursive call forward pointer
        become the head of upcoming all nodes
        */
        head->next = reverseKNodes(forward, k);
    }

    //step 3 return head of updated LL
    return prev;
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
    
    int k;
    cout<< "Enter the value of groups you want to reverse LL : "; cin>>k;
    head = reverseKNodes(head, k);
    print(head);

}