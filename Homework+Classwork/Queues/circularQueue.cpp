#include <iostream>
using namespace std;

class CirQueue{
    public : 

    int size;
    int *arr;
    int front;
    int rear;

    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data) {
        //check queue is full or not
        if((rear == size-1 && front == 0) || (front-rear == 1)) {
            cout<<"Circular Queue is full. \n";
        }
        //single element handle
        else if(front ==-1) {
            front = rear = 0;
            arr[rear] = data;
        }
        //handle the circular nature
        else if(rear == size && front != 0) {
            rear = 0;
            arr[rear] = data;
        }
        //default
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop() {
        //check empty
        if(front == -1) {
            cout<<"Queue is Empty. \n";
        }
        //single element
        else if(front == rear) {
            front = rear = -1;
        }
        //circular nature
        else if(front == size-1) {
            front = 0;
        }
        //normal
        else {
            front++;
        }
    }
};

int main() {
    CirQueue cir(10);

    cir.push(17);
    cir.push(18);
    cir.push(19);
    cir.push(11);
    cir.push(12);
}