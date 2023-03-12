#include <iostream>
using namespace std;

void printCount(int num) {
    //base case
    if(num==0) {
        return;
    }
    //processing
    cout<<num<<" ";

    //recursive relation
    printCount(num-1); //recursion calls func direcly and indirectly
}

int main() {
    int num;
    cout<<"Enter the value of num : ";cin>>num;
    printCount(num);
}