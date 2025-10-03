/*In this we have to update the ith bit according the target, if target is 1 change ith bit to 1 and if target is 0 change the ith bit to 0*/

#include <iostream>
using namespace std;

int clearKthBit(int& num, int k) { //by reference as we want to make the changes in the original num value
    int mask = ~(1<<k);
    num = num & mask;
}

int updateKthBit(int num, int k, int target) {
    //first we have to clear the kth bit so as we can apply same operation i.e Bitwise OR operator with some left shifts with the target
    clearKthBit(num, k);
    int mask = target << k;
    int value = num | mask;
    return value;
}

int main() {
    int num, k, target;
    cout<<"Enter the num "; cin>>num;
    cout<<"Enter the value of k "; cin>>k;
    cout<<"Enter the target : "; cin>> target;

    int val = updateKthBit(num, k, target);
    cout<<val;
}