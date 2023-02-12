#include <iostream>
using namespace std;

void reversearray(int arr[], int n) {
    for(int i=0; i<n/2; i++) {
        arr[i]=arr[i]^arr[n-i-1];
        arr[n-i-1]=arr[n-i-1]^arr[i];
        arr[i]=arr[i]^arr[n-i-1];
    }
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
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
    reversearray(arr,n);

    return 0;
}