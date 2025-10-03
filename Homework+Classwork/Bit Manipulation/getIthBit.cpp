#include <iostream>
using namespace std;

int getithBit(int num, int ith) {
    //create the mask
    int mask = 1 << ith;
    int ans = num & mask;
    if(ans == 0) return 0;
    else return 1;
}

int main() {
    int num, ith;
    cout<<"Enter the number : "; cin>>num; 
    cout<<"Enter the ith bit : "; cin>>ith;

    int bit = getithBit(num, ith); //here that last bit will be 0th bit then 1st bit and so on......
    cout << "The " << ith << " bit is " << bit << endl;
}