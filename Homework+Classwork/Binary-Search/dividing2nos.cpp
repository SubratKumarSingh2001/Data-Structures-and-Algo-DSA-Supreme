#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int divide2nos(int dividend, int divisor) {
    /* any dividend divided by any divisor than the quotient remains between 0 to dividend including dividend 
     so start will be 0 and end will be dividend*/
    int start=0, end=abs(dividend); //we use abs function to use absolute integer without its sign
    int ans=-1;
    //mid means quotient 
    int mid = start + (end-start)/2;
    while(start<=end) {
        // if quotient *divisor become equal to dividend i.e 12/2=6 -> 6*2=12 
        if(abs(mid*divisor)==abs(dividend)) {
            ans=mid; //it will storee the ans and break and check down whether the no is +ve or -ve
            break;
        }
        else if(abs(mid*divisor)>abs(dividend)) {
            end=mid-1;
        }
        else if(abs(mid*divisor)<abs(dividend)) {
            //first we will store the value as it could be the nearest quotient and then check in right
            ans=mid;
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    //it will work when a dividend and divisor is positive or negative 
    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) {
        return ans;
    }
    else {
        return -ans;
    }

}


int main() {
    int dividend, divisor;
    cout<<"Enter the value of dividend : ";cin>>dividend;
    cout<<"Enter the value of divisor : ";cin>>divisor;
    int quotient = divide2nos(dividend,divisor);
    double finalAns = abs(quotient);
    double step = 0.1;
    int decimal;
    cout<<"How many decimal after digits you want : ";cin>>decimal;
    for(int i=0; i<decimal; i++) {
        for(double j=finalAns; abs(j*divisor)<=abs(dividend); j+=step) {
            finalAns=j;
        }
        step=step/10;
    }
    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)) {
        cout<<"The dividend "<<dividend<<" when divided by "<<divisor<<" we get quotient "<<finalAns;
    }
    else{
        cout<<"The dividend "<<dividend<<" when divided by "<<divisor<<" we get quotient "<<-finalAns;
    }
}