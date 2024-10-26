#include <iostream>
#include <queue>
using namespace std;
/* 
   as queue can be used as STL(Structured Template Library) means its creation have been done befor 
   so we need not to create a queue we can just import it and have an access of its predefined functions. 
   But manually we can create a queue with help of arrays and linked list;
*/

int main() {
    //creation
    queue<int> q;

    //insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);
    
    //size of the queue
    cout<<"The size of queue is : "<<q.size() <<endl;

    //removal of element
    q.pop();
    cout<<"The size of queue is : "<<q.size() <<endl;
    
    //to check queue is empty or not
    if(q.empty()) {
        cout<<"Queue is empty. \n";
    }
    else  {
        cout<<"Queue is not Empty. \n";
    }

    //to print the front element of queue
    cout<<"The front element of queue is : " << q.front()<<endl;
    
    return 0;
}