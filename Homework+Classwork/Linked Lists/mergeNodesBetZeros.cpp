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

Node* mergeNodes(Node* &head) {
        //Brute Force
        //TC: O(n), n is length of the Linked List
        /*SC: O(m-1) = O(m) where m is the number of zero nodes in the Linked List or 
        the nodes segmented by 0 nodes. m<n and m != n (because the Linked List must have
        minimum of three node and atleast 1 node with non-zero value
        */
        Node* temp = head->next; //as there are minimum three nodes, head cant be NULL
        Node* dummyNode = new Node(-1);
        Node* ptr = dummyNode;
        int sum = 0;
        while(temp) {
            if(temp->val != 0) {
                sum += temp->val;
            }
            else {
                Node* newNode = new Node(sum);
                ptr->next = newNode;
                ptr = ptr->next;
                sum = 0;
            }
            temp = temp->next;
        }
        return dummyNode->next;

        // //Better Soluion
        // //TC: O(n+n = 2n) = O(n), SC: O(1) (No extra space taken)
        tNode* t1 = head;
        while(t1->next != NULL) {
            Node* t2 = t1->next;
            Node* t3 = t2->next;
            if(t3->val != 0) {
                t2->val = t2->val + t3->val;
                t2->next = t3->next;
            }
            else {
                t1 = t3;
            }
        }
        head = head->next; //to move ahead with initial 0 node
        t1 = head;
        while(t1) {
            Node* t2 = t1->next;
            t1->next = t2->next;
            t1 = t1->next;
        }
        return head;

        //Optimal Solution
        //TC: O(n), SC: O(1)
        Node* slow = head;
        Node* fast = slow->next;
        Node* last = NULL;
        int sum=0;
        while(fast) {
            if(fast->val != 0) {
                sum += fast->val;
            }
            else {
                slow->val = sum;
                last = slow;
                slow = slow->next;
                sum=0;
            }
            fast = fast->next;
        }
        last->next = NULL; // to make linked list separate

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
    mergeNodes(head);
    displayLL(head);
}