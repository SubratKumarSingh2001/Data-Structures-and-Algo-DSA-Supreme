#include <iostream>
using namespace std;

int main() {
    long long num;
    cout<<"Enter the number : "; cin>>num; 

    if(num&1) {
        cout<<"The number is odd number";
    }
    else {
        cout<<"The number is even number";
    }
}