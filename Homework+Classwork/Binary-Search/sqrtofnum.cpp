#include <iostream>
using namespace std;

int findsqrt(int num) {
    int start=0, end=num;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end) {
        if(mid*mid==num) {
            return mid;
        }
        else if(mid*mid>num) {
            end=mid-1;
        }
        else if(mid*mid<num) {
            ans=mid;
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main() {
    int num;
    cout<<"Enter the number whose square root need to be find : ";cin>>num;
    int sqrt = findsqrt(num);
    cout<<"The square root of "<<num<<" is "<<sqrt<<endl;
    double finalAns =sqrt;
    int decimal;
    cout<<"How much decimal after he number  do you need : ";cin>>decimal;
    double step =0.1;
    for(int i=0; i<decimal; i++) {
        for(double j=finalAns; j*j<=num; j=j+step) {
            finalAns = j;
        }
        step=step/10;
    }
    cout<<"The square root of "<<num<<" is "<<finalAns;
}