#include <iostream>
using namespace std;

void extremeprint(int arr[], int n) {
    int start=0;
    int end=n-1;
    while(start<=end){
        if(start==end){
            cout<<arr[start];
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";
        }
        start++;
        end--;
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
    extremeprint(arr, n);
}