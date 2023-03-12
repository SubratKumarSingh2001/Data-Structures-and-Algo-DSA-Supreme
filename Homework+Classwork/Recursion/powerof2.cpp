#include <iostream>
using namespace std;

int powerOftwo(int num) {
    //base case
    if(num==0) {
        return 1;
    }

    //recursive relation 
    int ans = 2* powerOftwo(num-1);

    return ans;
}

int main() {
    int num;
    cout<<"Enter the value of num : ";cin>>num;
    int power = powerOftwo(num);
    cout<<"The power of 2^"<<num<<" is : "<<power;
}