#include <iostream>
#include <limits.h>
using namespace std;

int findmaxno(int arr[], int num){
    int maxi= INT_MIN;
    for(int i=0; i<num; i++) {
        if(arr[i]>maxi) {
            maxi=arr[i];
        }
    }
    return maxi;
}
int main() {
    int arr[50];
    int n;
    cout<<"Enter the number of element want in array : "; cin>>n;
    for(int i=0; i<n; i++) { // input of arrays
        cin>>arr[i];
    }
    for(int i=0; i<n; i++) { // printing the arrays
       cout<<arr[i]<<" ";

    }
    cout<<endl;
    int maxi = findmaxno(arr, n);
    cout<<"The max no in array is : "<<maxi;

}