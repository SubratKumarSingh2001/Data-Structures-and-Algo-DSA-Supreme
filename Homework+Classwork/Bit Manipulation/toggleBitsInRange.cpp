/*
Given a non-negative number n and two values l and r. The problem is to toggle the bits in the range [l,r] in the binary representation of n, 
i.e., to toggle bits from the lth least significant bit to the rth least significant bit (the rightmost bit as counted as the first bit).
*/

//Important Question

#include <iostream>
using namespace std;

int toggleKthBit(int num, int l, int r) {
    int a = (1 << r) - 1; //-1 because to make 0000..1000-> 0000..0111;
    int b = ((1 << (l-1)) - 1); // to make 0000...100-> 00000...011
    int mask = a ^ b;
     
    return num ^ mask;;
}

int main() {
    int num, l, r;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of l and r "; cin>>l>>r;

    int val = toggleKthBit(num, l, r);
    cout<<val;
}