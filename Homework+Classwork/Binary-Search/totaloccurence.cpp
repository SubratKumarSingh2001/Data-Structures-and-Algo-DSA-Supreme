#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    int ans1 =-1;
    while(start<=end) {
        if(target == arr[mid]) {
            ans1 = mid;
            end =mid-1;
        }
        else if(target < arr[mid]) {
            end =mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans1;
}

int lastOccurence(vector<int> arr, int target) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    int ans2 =-1;
    while(start<=end) {
        if(target == arr[mid]) {
            ans2 = mid;
            start=mid+1;
        }
        else if(target < arr[mid]) {
            end =mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans2;
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the number whose total occurence need to be find : ";cin>>target;
    int fistoccur = firstOccurence(arr,target);
    int lastoccur = lastOccurence(arr,target);
    int totalOccurence = lastoccur-fistoccur+1;
    cout<<"The total occurence of a number is : "<<totalOccurence;
}