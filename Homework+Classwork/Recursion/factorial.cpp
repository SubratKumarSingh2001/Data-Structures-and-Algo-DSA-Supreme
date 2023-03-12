#include <iostream>
using namespace std;

int factorial(int num) {
    //base case
    if(num==1) {
        return 1;
    }
    //recursive relation 
    int fact = num * factorial(num-1);

    return fact;
}

int main() {
    int num;
    cout<<"Enter the number whose factorial need to be find : ";cin>>num;
    int fact = factorial(num);
    cout<<"The factorial of "<<num <<" is "<<fact;
}