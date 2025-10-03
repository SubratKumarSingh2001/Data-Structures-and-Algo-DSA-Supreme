//Toggling the bit means change 0 to 1 or 1 to 0, if the kth bit is 0 make it 1 or if the kth bit is 1 make it 0 means we ahve to toggle it 

#include <iostream>
using namespace std;

int toggleKthBit(int num, int k) {
    int mask = ~(-1 << k);
    int value = num ^ mask;

    return value;
}

int main() {
    int num, k;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of k "; cin>>k;

    int val = toggleKthBit(num, k);
    cout<<val;
}