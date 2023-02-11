#include <iostream>
using namespace std;

bool findnum(int arr[], int n, int num) { // to check that the number match with any element of an array
    for(int i=0; i<n; i++) {
        if(arr[i]==num) {
            return true;
        }
    }
    return false;
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
    int num;
    cout<<"Enter the num to find : "; cin>>num; // to find which number
    if(findnum(arr, n, num)) {
        cout<<"Number Found";
    }
    else{
        cout<<"Not Found";
    }
}