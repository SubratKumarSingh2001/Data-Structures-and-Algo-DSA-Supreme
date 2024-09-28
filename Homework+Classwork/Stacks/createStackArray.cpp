/*
We can manually create an array either with the help of array or linked list. In this we are
going to create an array with the help of dynamic array.
*/

#include <iostream>
using namespace std;

class Stack{
    public: 
    //properties
    int top; //index to access the top ele of an array
    int *arr; //dynamic array address hold by pointer
    int size; //maximum size of an array(not no.of element in an array)

    //constructor
    Stack(int size) {
        arr = new int[size]; //dynamic array creation
        this->size = size;
        top = -1;
    }
    
    //behaviors
    
    //insert the ele in stack
    void push(int data) {
        if(size-top > 1) {
            top++;
            arr[top] = data;
        }
        else {
            cout<<"Stack Overflow. \n";
        }
    }
    
    //remove the ele from the stack
    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow, Cant't delete the element. \n";
        }
        else {
            top--; //basically we are not deleting the ele just changing the top
        }
    }

    //to get the top element of stack
    int getTop() {
        if(top == -1) {
            cout<<"Stack is empty, Therefore no top element is present. \n";
        }
        else {
            return arr[top];
        }
    }
    
    //basically to find the no of valid elements in Stack
    int getSize() {
        return top+1;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    while(!st.isEmpty()) {
        cout<<st.getTop()<<" ";
        st.pop();
    }
    cout<<endl;
    
    
}