//Division method of conversion of decimal to binary

#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int num) {
    //step1 divide the num until quotient is less than 2
    int binary = 0;
    int i = 0;
    while(num>0) {
        int bit = num%2;
        binary = bit*pow(10,i++)+binary;
        num /= 2;
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