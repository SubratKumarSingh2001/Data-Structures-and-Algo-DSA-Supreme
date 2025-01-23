#include <iostream>
#include <vector>
using namespace std;

void sort0s1sand2s(vector<int> &arr) { //passing vector as pass by reference changes made here will reflect back to original array
    int zeros=0, ones=0, twos=0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 0) zeros++;
        else if(arr[i] == 1) ones++;
        else if(arr[i] == 2) twos++;
    }
        
    int i=0;
    while(zeros) {
        arr[i] = 0;
        i++;
        zeros--;
    }
    while(ones) {
        arr[i] = 1;
        i++;
        ones--;
    }
    while(twos) {
        arr[i] = 2;
        i++;
        twos--;
    }
}

int main() {
    int size;
    cout<<"Enter the size of the vector : "; cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    sort0s1sand2s(arr);
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}