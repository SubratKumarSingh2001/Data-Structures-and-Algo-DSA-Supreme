#include <iostream>
using namespace std;

int cntSetBits(int num) {
    One way
    int cnt = 0;
    while(num) {
        if(num&1) cnt++;
        num = num >> 1;
    }
    return cnt;

    //Another way
    int cnt = 0;
    while(num) {
        num = (num & (num-1));
        cnt++;
    }
    return cnt;
}

int main() {
    int num;
    cout << "Enter the number : "; cin >> num;

    cout << "The number of set bits are : " << cntSetBits(num) << endl;
}