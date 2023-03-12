#include <iostream>
using namespace std;

void printDigits(int num) {
    //base case
    if(num==0) {
        return;
    }

    //recursive relation (HEAD Recursion)
    printDigits(num/10);

    //processing 
    int rem = num%10;
    cout<< rem<<" ";

}

int main() {
    int num;
    cout<<"Enter the number : ";cin>>num;
    if(num==0){
        cout<<0;
    }
    printDigits(num);
}