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
Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr -> next;
        while(curr != NULL) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
        }
        return prev;
}
Node* solve(Node* &head1, Node* &head2) {

        if(head1 == NULL)
                return head2;
        if(head2 == NULL)
                return head1; 

        //step1 : reverse both linked list
        head1 = reverse(head1);
        head2 = reverse(head2);

        //step2: add both linked list
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        int carry = 0;

        while(head1 != NULL && head2 != NULL) {
                //calculate sum
                int sum = carry + head1 -> data + head2 -> data;
                //find digit to create node for
                int digit = sum % 10;
                //calculate carry
                carry = sum / 10;

                //create a new Node for the digit
                Node* newNode = new Node(digit);
                //attach the newNode into the answer wali linked list
                if(ansHead == NULL) {
                        //first node insert krre ho
                        ansHead = newNode;
                        ansTail = newNode;
                }
                else {
                        ansTail -> next = newNode;
                        ansTail = newNode;
                }
                head1 = head1 -> next;
                head2 = head2 -> next;
        }

        //jab head1 list ki length head2 list se jada hogi
        while(head1 != NULL) {
                int sum = carry + head1 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head1 = head1 -> next;
        }

        //jab head2 list ki length head1 list se jada hogi
        while(head2 != NULL) {
                int sum = carry + head2 -> data;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
                head2 = head2 -> next;
        }

        //handle carry ko alag se
        while(carry != 0) {
                int sum = carry;
                int digit = sum % 10;
                carry = sum / 10;
                Node* newNode = new Node(digit);
                ansTail -> next = newNode;
                ansTail = newNode;
        }


        //step3: reverse the ans linked list
        ansHead = reverse(ansHead);
        return ansHead;
}

int main() {
        Node* head1 = new Node(9);
        Node* second1 = new Node(9);
        head1 -> next = second1;

        Node* head2 = new Node(9);
        Node* second2 = new Node(9);
        // Node* third2 = new Node(4);
        head2 -> next = second2;
       // second2 -> next = third2;

        Node* ans = solve(head1, head2);

        print(ans);


        return 0;
}