#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int>arr) {
    int start=0, end=arr.size()-1;
    int mid= start + (end-start)/2;
    while(start<end) {
        if(arr[mid]<arr[mid+1]) {
            start=mid+1;
        }
        else if(arr[mid]>arr[mid+1]) {
            end = mid;
        }
        mid= start + (end-start)/2;
    }
    return start;
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int peak = peakElement(arr);
    cout<<"The peak element is at index : ";cout<<arr[peak];
}