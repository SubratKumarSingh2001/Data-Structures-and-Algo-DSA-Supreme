#include <iostream>
using namespace std;

bool checkPowOfTwo(int num) {
    // //One way
    // //in case of the number which are in power of 2 there is only 1 set bit like 2 = 10, 4 = 100, 8 = 1000, 16 = 10000, so we will count the no.of set bits
    // int cnt = 0;
    // while(num) {
    //     if(num & 1) cnt ++;
    //     num = num >> 1;
    // }
    // if(cnt == 1) return true;
    // return false;

    //Another way
    //If a number is power of two then its bitwise and operation with previous number will give us 0 i.e 16 & 15 = 0, 8 & 7 = 0
    return (num & (num-1)) == 0 ? true : false; 
}

int main() {
    int num; 
    cout<<"Enter the number which you want to whether it is power of 2 or not : "; cin >> num;

    if(checkPowOfTwo(num)) {
        cout<<"The " << num << " can be raised in the power of two " << endl;
    }
    else {
        cout<<"The " << num << " cannot raised in the power of two " << endl;
    }
}