#include <iostream>
using namespace std;

int clearTheLastContKthBit(int num, int k) {
    int mask = (-1 << k);
    int val = num & mask;

    return val;
}

int main() {
    int num, k, target;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of k (No.of bits from last we want to change) : "; cin>>k;

    int val = clearTheLastContKthBit(num, k);
    cout<<val;
}