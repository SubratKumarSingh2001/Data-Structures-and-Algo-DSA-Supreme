#include <iostream>
#include <vector>
using namespace std;

//simple binary search to search an element 
int binarySearch(vector<int> arr, int start, int end, int target) {
    int mid=start+ (end-start)/2;
    while(start<=end) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(target>arr[mid]) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
        mid=start+ (end-start)/2;
    }
    return -1;
} 

int findExponentialSearch(vector<int> arr, int target) {
    int n = arr.size();
    //if our target is found at first index then return the index 0
    if(arr[0]==target) {
        return 0;
    }
    int i=1;
    //it will check whether the i less then array size and arr[i] less than equal to target then we will check
    // i*=2 when condition break do binary search from previous i value to current i value
    while(i<n && arr[i]<=target) {
        i*=2;
    }
    //we here are using min function because when we do i*=2 at some point the index may go out of bound means 
    // out of index and we wont be able to find the element through binary search
    return binarySearch(arr, i/2, min(i,n-1), target);
}

int main() {
    int num;
    cout<<"Enter the size of a vector : ";cin>>num;
    vector<int>arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the number need to be found : ";cin>>target;
    // to do exponential search
    int index = findExponentialSearch(arr, target);
    cout<<"The target is found at index : "<<index;
}