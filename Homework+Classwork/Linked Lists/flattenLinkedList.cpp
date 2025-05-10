#include <iostream>
using namespace std;

class Node {
    public : 
        int val;
        Node* next;
        Node* bottom;

        Node() {
            this->val = 0;
            this->next = NULL;
            this->bottom = NULL;
        }
        Node(int val) {
            this->val = val;
            this->next = NULL;
            this->bottom = NULL;
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

Node* mergeTwoLL(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* t3 = dummyNode;
    while(t1 && t2) {
        if(t1->val <= t2->val) {
            t3->bottom = t1;
            t1 = t1->bottom;
        }
        else {
            t3->bottom = t2;
            t2 = t2->bottom;
        }
        t3 = t3->bottom;
    }
    
    while(t1) {
        t3->bottom = t1;
        t1 = t1->bottom;
        t3 = t3->bottom;
    }
    while(t2) {
        t3->bottom = t2;
        t2 = t2->bottom;
        t3 = t3->bottom;
    }
    
    return dummyNode->bottom;
}
// Function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    // Your code here
    /*Brute Force by storing all the element of ll in an array then
    sorting and then convert the array into again Ll
    */
    //TC: O(2*n*m) SC: O(2*n*m)
    // vector<int> ans;
    // Node* temp = root;
    // while(temp) {
    //     Node* t1 = temp;
    //     while(t1) {
    //         ans.push_back(t1->data);
    //         t1 = t1->bottom;
    //     }
    //     temp = temp->next;
    // }
    // //now sort the array
    // sort(ans.begin(), ans.end());
    // //now create the linked list
    // Node* dummyNode = new Node(-1);
    // temp = dummyNode;
    // for(int i=0; i<ans.size(); i++) {
    //     Node* newNode = new Node(ans[i]);
    //     temp->bottom = newNode;
    //     temp = temp->bottom;
    // }
    
    // return dummyNode->bottom;
    
    //Optimal Code
    /*
    TC: O(2m)+O(3m)+O(4m).........O(mn)
    = O(m(1+2+3+4.......n-1) = O((m*(n^2+2n-2))/2
    =O(m*(n-1)(n+2)/2 
    = O(m*n*n): TC
    */
    //SC: O(n), due to the recursive call stacks
    //base case 
    if(root->next == NULL) {
        return root;
    }
    
    Node* t1 = root;
    Node* t2 = t1->next;
    Node* t3 = NULL;
    if(t2) {
        t3 = t2->next;
    }
    
    //merge the two linked list to flattern it 
    Node* newHead = mergeTwoLL(t1, t2);
    /*we make sure that newHead point t3 bcz we are taking t1 and
    t2 corresponding nodes and t1->next must be t2
    */
    newHead->next = t3;
    
    //now we have to again merge the LL with remaining linked list
    flatten(newHead);   
    
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
    flatten(head);
    displayLL(head);
}