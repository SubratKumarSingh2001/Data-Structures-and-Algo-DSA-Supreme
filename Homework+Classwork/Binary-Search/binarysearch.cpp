#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>arr, int target) {
    int start=0, end=arr.size()-1;
    int mid= start + (end-start)/2;
    while(start<=end) {
        if(target == arr[mid]) {
            return mid;
        }
        else if(target<arr[mid]) {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid= start + (end-start)/2;
    }
    return -1;
} 

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element need to be found at index : ";cin>>target;
    int searchElement = binarySearch(arr,target);
    if(searchElement==-1) {
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at : "<<searchElement;
    }
}