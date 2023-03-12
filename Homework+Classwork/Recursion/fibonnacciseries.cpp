#include <iostream>
using namespace std;

int fibonnacci(int num) {
    //base case 
    if(num==1) {
        return 0;
    }
    if(num==2) {
        return 1;
    }

    //recursive relation 
    return fibonnacci(num-1)+fibonnacci(num-2);
}
int main() {
    int num;
    cout<<"Enter the nth term : ";cin>>num;
    int fib = fibonnacci(num);
    cout<<"The fibonnacci of "<<num<<"th "<<"term is "<<fib;
}