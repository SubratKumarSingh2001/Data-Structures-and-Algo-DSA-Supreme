//set ith bit means we have to make the ith bit 1 and if it already 1 then keep it as it is
#include <iostream>
using namespace std;

int setKthBit(int num, int k) {
    int mask = 1<<k;
    int value = num | mask;

    return value;
}

int main() {
    int num, k;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of k "; cin>>k;

    int val = setKthBit(num, k);
    cout<<val;
}