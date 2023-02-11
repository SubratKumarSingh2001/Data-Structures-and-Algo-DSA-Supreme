#include <iostream>
using namespace std;

void find0and1(int arr[], int n){
    int total0 =0;
    int total1 =0;
    for(int i=0; i<n; i++){
        if(arr[i]==0) {
            total0++;
        }
        if(arr[i]==1) {
            total1++;
        }
    }
    cout<<"Total 0's are : "<<total0<<endl;
    cout<<"Total 1's are : "<<total1;
}

int main() {
    int n;
    int arr[50];
    cout<<"Enter the number of element want in array : "; cin>>n;
    for(int i=0; i<n; i++) { // input of arrays
        cin>>arr[i];
    }
    for(int i=0; i<n; i++) { // printing the arrays
       cout<<arr[i]<<" ";

    }
    cout<<endl;
    find0and1(arr, n);

    return 0;
}