#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int num) {
    int binary = 0;
    int i = 0;
    while(num > 0) {
        int bit = num & 1;
        binary = bit*pow(10, i++) + binary;
        num = num >> 1;
    }
    return binary;
}

int main() {
    int num;
    cout<<"Enter the number want to convert into binary : "; cin>>num;
    int binary = decimalToBinary(num);
    cout<<"The binary represent of " <<num <<" is " <<binary;

    return 0;
}