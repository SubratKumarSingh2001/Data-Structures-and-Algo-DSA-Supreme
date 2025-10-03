//in this we have to make the ith bit 0
#include <iostream>
using namespace std;

int clearKthBit(int num, int k) {
    int mask = ~(1<<k);
    int value = num & mask;

    return value;
}

int main() {
    int num, k;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of k "; cin>>k;

    int val = clearKthBit(num, k);
    cout<<val;
}