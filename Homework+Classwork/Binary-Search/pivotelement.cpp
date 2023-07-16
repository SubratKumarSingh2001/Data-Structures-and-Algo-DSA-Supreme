#include <iostream>
#include <vector>
using namespace std;

int searchPivotIndex(vector<int> arr) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    /* run loop until start>= end */
    while(start <= end) {
        /* if arr[mid]>arr[mid+1] so we are at pivot index bcz right to pivot element all element are small
        and is increasing sorted order
        */
        if(arr[mid] > arr[mid+1]) {
            return mid;
        }
        /* if arr[mid-1]>arr[mid] we say pivot element is left to arr[mid] bcz the element next to pivot
        element would be smaller than pivot element
        */
        else if(arr[mid-1] > arr[mid]) {
            return mid-1;
        }
        /* now to check whether to move right or left of an array we can compare it through arr[start] 
        if arr[start]<arr[mid] means pivot element is in right of an array 
        */
        else if(arr[start] < arr[mid]) {
            start = mid+1;
        }
        /* if arr[start]>arr[mid] so we can say that our pivot element is in left of an array to move
        end = mid-1
        */
        else if(arr[start] > arr[mid]) {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}


int main() {
    int num;
    cout<<"Enter the size of a vector : ";cin>>num;
    vector<int>arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int pivotIndex = searchPivotIndex(arr);
    cout<<"The pivot index is : " << pivotIndex;
}