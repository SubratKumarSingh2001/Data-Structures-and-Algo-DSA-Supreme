#include <iostream>
using namespace std;

class Queue {
    public :
        int *arr; //dynamic array
        int size; // maximum size of an queue 
        int front; // front variable to point thr first ele of a queue
        int rear; // rear variable to point the last ele of a queue

        //initialisation
        Queue(int size) {
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        //push the element
        void push(int data) {
            if(rear == size) {
                cout<<"Queue is Full. \n";
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }

        //pop the element
        void pop() {
            if(front == rear) {
                cout<<"Queue is Empty. \n";
            }
            else {
                front++;
                /*
                there could be case where both front and rear point to same index means insert element
                began from that particular index but there is still no element to the left so we can 
                initialize the initial value of front and rear
                */
               if(front == rear) {
                    front = 0;
                    rear = 0;
               }
            }
        }

        // to check empty or not queue
        bool isEmpty() {
            if(front == rear) {
                return true;
            }
            else {
                return false;
            }
        }

        //to get front value of queue
        int getFront() {
            if(front == rear) {
                cout<<"Queue is Empty. \n";
                return -1;
            }
            else {
                return arr[front];
            }            
        }

        //size of the queue
        int getSize() {
            return rear - front; // as rear always point to the empty block so rear-front not rear-front+1
        }
};

int main() {
    Queue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout<<"Enter the size of the Queue is : "<< q.getSize() <<endl;

    q.pop(); 

    cout<<"Enter the size of the Queue is : "<< q.getSize() <<endl;
    
    cout<<"The Front element of a Queue is : "<<q.getFront() <<endl;

    if(q.isEmpty()) {
        cout<<"Queue is Empty. \n";
    }
    else {
        cout<<"Queue is not Empty. \n";
    }
}