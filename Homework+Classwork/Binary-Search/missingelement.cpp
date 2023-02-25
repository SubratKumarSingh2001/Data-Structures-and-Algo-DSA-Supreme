#include <iostream>
#include <vector>
using namespace std;

int findmissingele(vector<int> arr) {
    int start=0, end=arr.size()-1;
    int mid = start+(end-start)/2;
    while(start<=end) {
        //if start and end point to same element then there is only element then the missing element will be
        if((mid+1< arr.size()) && (start == end)) { // index of start + 1. also mid+!<arr.size() if there is no 
            return start+1; // missing element then it should not check the index which is not present just return -1
        }
        else if(mid+1 == arr[mid]) { // if mid+1 is equal to arr[mid] then missing element is in right
            start =mid+1;
        }
        else { // else if mid+1 not equal to arr[mid] then it the missing element can lie just left to mid;
            end=mid; //so we dont want to loose mid
        }
        mid = start+(end-start)/2;
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
    int missing = findmissingele(arr);
    cout<<"The missing element is  : "<<missing;
}