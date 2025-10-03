#include <iostream>
using namespace std;

int setRightmostUnsetBit(int num) {
    //TC: O(logn), SC: O(1)
    int mask = 1;
    int n = num;
    while(n) {
        if(n&1) {
            mask = mask << 1;
        }
        else break;
        n= n >> 1;
    }
    return num | mask;
        
    //TC: O(1), SC: O(1)
    return n | (n+1);
}

int main() {
    int num, k;
    cout<<"Enter the num "; cin>>num;

    int val = setRightmostUnsetBit(num);
    cout<<val;
}