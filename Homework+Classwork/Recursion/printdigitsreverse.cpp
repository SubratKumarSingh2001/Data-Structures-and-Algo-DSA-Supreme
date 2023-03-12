#include <iostream>
using namespace std;

void printDigits(int num) {
    //base case
    if(num==0) {
        return;
    }

    //processing 
    int rem = num%10;
    cout<< rem<<" ";

    //recursive relation (TAIL Recursion)
    printDigits(num/10);
}

int main() {
    int num;
    cout<<"Enter the number : ";cin>>num;
    if(num==0){
        cout<<0;
    }
    printDigits(num);
}