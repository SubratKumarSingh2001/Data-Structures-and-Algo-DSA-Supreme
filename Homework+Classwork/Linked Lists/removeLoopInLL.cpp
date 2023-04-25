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

bool checkForLoopInLL(Node* &head) {
    //if LL is empty
    if(head == NULL) {
        cout << "LL is empty " <<endl;
        return false;
    }

    //generic case create slow and fast pointer
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        //we cant move fast 2 step ahead a time i.e fast->next->next as fast->next maybe NULL
        //we will move fast 1 step ahead
        fast = fast->next;
        //now we will again check whether fast next is NULL or not
        if(fast != NULL) {
            fast = fast->next; //2nd step of fast
            slow = slow->next; //1 step of slow if fast is able to take 2 steps
        }

        /*to check loop is present the slow and fast pointer will meet at same node */
        if(slow == fast) {
            //means loop is present
            return true;
        }
    }
    //fast == NULL then loop is not present 
    return false;
}

Node* startingPointOfLoop(Node* &head) {
    //if LL is empty
    if(head == NULL) {
        cout << "LL is empty " <<endl;
    }

    //generic case create slow and fast pointer
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        //we cant move fast 2 step ahead a time i.e fast->next->next as fast->next maybe NULL
        //we will move fast 1 step ahead
        fast = fast->next;
        //now we will again check whether fast next is NULL or not
        if(fast != NULL) {
            fast = fast->next; //2nd step of fast
            slow = slow->next; //1 step of slow if fast is able to take 2 steps
        }

        /*to check loop is present the slow and fast pointer will meet at same node */
        if(slow == fast) {
            //when slow and fast become equal then assign slow = head
            slow = head;
            break;
        }
    }

    //now we will move slow and fast 1-1 step together until slow and fast become equal
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    //when slow and fast become equal after 1-1 step each of slow and fast then return either slow or fast
    return slow;
    
}

void removeLoop(Node* &head) {
    //if LL is empty
    if(head == NULL) {
        cout << "LL is empty " <<endl;
    }

    //generic case create slow and fast pointer
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL) {
        //we cant move fast 2 step ahead a time i.e fast->next->next as fast->next maybe NULL
        //we will move fast 1 step ahead
        fast = fast->next;
        //now we will again check whether fast next is NULL or not
        if(fast != NULL) {
            fast = fast->next; //2nd step of fast
            slow = slow->next; //1 step of slow if fast is able to take 2 steps
        }

        /*to check loop is present the slow and fast pointer will meet at same node */
        if(slow == fast) {
            //when slow and fast become equal then assign slow = head
            slow = head;
            break;
        }
    }

    //now we will move slow and fast 1-1 step together until slow and fast become equal
    //prev pointer will equal to fast to make last node as NULL 
    Node *prev = fast;
    while(slow != fast) {
        //first we will store fast in prev and then we will move fast 1 node ahead 
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    //at some time fast and slow will become equal then then prev pointer will be one step back to fast 
    //then make it null
    prev->next = NULL;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third; 
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = second;

    cout<< "The Loop is present in Linked List or not : " << checkForLoopInLL(head) <<endl;
    cout<< "The starting point of Loop in Linked List is :"<< startingPointOfLoop(head)->data <<endl;
    removeLoop(head);
    cout<<"Now the loop is removed and the Linked List is as follows : " <<endl;
    print(head);
    cout<<endl;
    cout<< "The Loop is present in Linked List or not : " << checkForLoopInLL(head) <<endl;

}