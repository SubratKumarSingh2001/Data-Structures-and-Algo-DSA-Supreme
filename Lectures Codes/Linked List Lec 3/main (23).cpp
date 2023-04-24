#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this -> data = data;
                this -> next = NULL;
        }
};

void print(Node* head) {
        Node* temp = head; 
        while(temp != NULL) {
                cout << temp -> data << " ";
                temp = temp -> next;
        }
        cout << endl;
}

Node* getMiddle(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty" << endl;
                return head;
        }
        if(head -> next == NULL) {
                //only 1 node in LL
                return head;
        }

        // LL have > 1 node
        Node* slow = head;
        Node* fast = head;

        while(slow != NULL && fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }
        }
        return slow;
}

int getLength(Node* head) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp -> next; 
                len++;
        }
        return len;
}

Node* reverseKNodes(Node* &head, int k) {
        if(head == NULL) {
                cout << "LL is empty" << endl;
                return NULL;
        }
        int len = getLength(head);
        if(k > len) {
                //cout << "Enter valid value for k " << endl;
                return head;
        }

        //it means number of nodes in LL is >= k
        //Step A: reverse first k nodes of LL
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = curr -> next;
        int count = 0;

        while(count < k) {
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                count++;
        }

        //Step B: recursive call
        if(forward != NULL) {
                // we still have nodes left to reverse
                Node* recursionKaAns = reverseKNodes(forward, k);
                head -> next = recursionKaAns;
        }

        //step C: return head of the modified LL
        return prev;
}

bool checkForLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return false;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                        //loop present
                        return true;
                }
        }
        //fast NULL hogya
        return false;

}

Node* startingPointLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        while(slow != fast) {
                slow = slow -> next;
                fast =fast -> next;
        }

        return slow;
        

}

Node* removeLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        slow = slow -> next;
                }

                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }

        Node* prev = fast;
        while(slow != fast) {
                prev = fast;
                slow = slow -> next;
                fast =fast -> next;
        }
        prev -> next = NULL;
        return slow;
}

 
int main() {
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);
  Node* sixth = new Node(60);
  Node* seventh = new Node(70);
  Node* eighth = new Node(80);
  Node* ninth = new Node(90);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth -> next = seventh;
  seventh -> next = eighth;
  eighth -> next = ninth;
  ninth -> next = fourth;

  //print(head);
//   head = reverseKNodes(head, 5);
//   print(head);

  //cout << "Middle Node is: " << getMiddle(head) -> data << endl;

  cout << "Loop is Present or not " << checkForLoop(head) << endl;
  cout << "Starting Point of LOOP is: " << startingPointLoop(head) -> data << endl;
  removeLoop(head);
  print(head);
cout << "Loop is Present or not " << checkForLoop(head) << endl;


  return 0;
}