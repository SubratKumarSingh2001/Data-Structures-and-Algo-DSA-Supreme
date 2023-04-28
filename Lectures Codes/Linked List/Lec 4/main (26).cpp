#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
                this->data = data;
                this->next = NULL;
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

void removeDuplicates(Node* &head) {
        if( head == NULL) {
                cout << "LL is empty" << endl;
                return;
        }
        if(head -> next == NULL) {
                cout << "Single Node in LL" << endl;
                return ;
        }

        // >1 node in LL
        Node* curr = head;

        while(curr != NULL) {
                if((curr -> next != NULL) && (curr -> data == curr -> next -> data) ) {
                        //equal
                        Node* temp = curr -> next;
                        curr -> next = curr -> next -> next;
                        //delete node
                        temp -> next = NULL;
                        delete temp;
                }
                else {
                        // not equal
                        curr = curr -> next;
                }
        }


}

int main() {

  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(2);
  Node* fourth = new Node(3);
  Node* fifth = new Node(4);
  Node* sixth = new Node(4);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;

  cout << "input LL: ";
  print(head);

  removeDuplicates(head);
  cout << "output LL: " ;
  print(head);




  return 0;
}