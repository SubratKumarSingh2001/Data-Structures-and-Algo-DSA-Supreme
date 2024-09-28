#include <iostream>
#include <stack> 
using namespace std;
/* 
   as stack can be used as STL(Structured Template Library) means its creation have been done befor 
   so we need not to create a stack we can just import it and have an access of its predefined functions. 
   But manually we can create a stack with help of arrays and linked list;
*/

int main() {

    stack<int> st; //int type stack same as vectors

    //insert in stack with push keyword
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    //delete in stack
    st.pop();

    //top element of stack
    cout<<"Element at the top of stack is: "<<st.top()<<endl;

    //to find the size of the stack
    cout<<"Size of the stack is : "<<st.size()<<endl;

    //to check the stack is empty or not
    if(st.empty()) {
        cout<<"Stack is empty. \n";
    }
    else{
        cout<<"Stack is not empty. \n";
    }

    //to print the element of stack
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}