#include <iostream>
using namespace std;

int reverseNo(int num) {
    int reverse =0;
    for(int i=num; i>0; i/=10) {
        int rem = i%10;
        reverse= reverse*10 + rem;
    }
    return reverse;
}

int main() {
    int n;
    cout<<"Enter the number want to do reverese : "; cin>>n;
    int reverse = reverseNo(n);
    cout<<"The reverse of "<<n<<" is "<<reverse;

    return 0;
}