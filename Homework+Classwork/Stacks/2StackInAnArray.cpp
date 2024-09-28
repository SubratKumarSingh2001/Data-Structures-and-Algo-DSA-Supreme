#include <iostream>
using namespace std;

class Stack{
    public:
        int top1;
        int top2;
        int *arr;
        int size; //max side of an array i.e max element an array can take

        //constructor: initialize the members
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top1 = -1;
            top2 = size;
        } 

        //behaviors

        //to insert ele in stack 1 that being added in single array
        void push1(int data) {
            if(top2-top1 == 1) {
                cout<<"Overflow in Stack 1. \n";
            }
            else{
                top1++;
                arr[top1] = data;
            }
        }
        
        //to pop out the element from stack 1 that being present in single array
        void pop1() {
            if(top1 == -1) {
                cout<<"Underflow in Stack 1. \n";
            }
            else {
                top1--;
            }
        }
        
        //to insert ele in stack 2 that being added in single array
        void push2(int data) {
            if(top2-top1 == 1) {
                cout<<"Overflow in Stack 2. \n";
            }
            else {
                top2--;
                arr[top2] = data;
            }
        }
        
        //to pop out the element from stack 2 that being present in single array
        void pop2() {
            if(top2 == size) {
                cout<<"Underflow in Stack 2. \n";
            }
            else {
                top2++;
            }
        }

        void print() {
            for(int i=0; i<size; i++) {
                cout << arr[i] <<" ";
            }
            cout<<endl;
        }
};

int main() {
    
    Stack st(10);

    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push1(40);
    st.push1(50);

    st.push2(100);
    st.push2(110);
    st.push2(120);
    st.push2(130);
    st.push2(140);

    st.print();
}