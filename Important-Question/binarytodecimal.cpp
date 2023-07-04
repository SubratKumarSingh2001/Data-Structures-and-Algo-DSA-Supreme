#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(int binary) {
    int decimal = 0;
    int i = 0;
    while(binary) {
        int bit = binary % 10;
        decimal = decimal + bit * pow(2, i++);
        binary /= 10;
    }
    return decimal;
}

int main() {
    int binary;
    cout<<"Enter the binary want to convert into decimal : "; cin>>binary;
    int decimal = binaryToDecimal(binary);
    cout<<"The binary represent of " <<binary <<" is " <<decimal;

    return 0;
}