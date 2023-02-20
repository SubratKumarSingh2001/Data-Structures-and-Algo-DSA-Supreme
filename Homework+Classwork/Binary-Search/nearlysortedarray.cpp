#include <iostream>
#include <vector>
using namespace std;

/*
Nearly sorted array means an element which is present at ith index of sorted array will be present at ith index
or i+1th index or i-1th index of nearly sorted array;
*/

int nearlysortedarray(vector<int>arr, int target) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        //now you have to check 3 cases whether target is present at mid, mid+1 or mid-1 bcz acc to def of 
        // nearly sorted array
        if(arr[mid]==target) {
            return mid;
        }
        else if(arr[mid-1]==target) {
            return mid-1;
        }
        else if(arr[mid+1]==target) {
            return mid+1;
        }
        else if(arr[mid]>target) {
            //left search here -2 bcz we have already check mid, mid-1 it will be useless to check mid-1 again
            end=mid-2;
        }
        else if(arr[mid]<target) {
            //right search here +2 bcz we have already checked mid and mid+1 will be useless to check mid+1 again
            start=mid+2;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}
int main() {
    int num;
    cout<<"Enter the size of vector : ";cin>>num;
    vector<int>arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the number needed to be find : ";cin>>target;
    int search = nearlysortedarray(arr, target);
    cout<<"The number found at index : "<<search;
}
