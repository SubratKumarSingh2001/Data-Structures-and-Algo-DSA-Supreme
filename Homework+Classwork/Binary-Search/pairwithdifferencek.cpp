#include <iostream>
#include <vector>
using namespace std;
/*
We need to find the pairs that will give the difference ex: we have a sorted array 1,2,3,4,5,6 and we want
difference of 1. Then the pairs could be (1,2) (2,3) (3,4) (4,5) (5,6). 

Approach I used is creating two user defined functions one that will handle the first element of a pair and
second element of a pair can be searched by binary search done below.
*/

//binary search to find the 2nd element of a pair which can be easily find with normal way
int binarySearch(vector<int> arr, int target) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid]==target) {
            return mid;
        }
        else if(arr[mid]>target) {
            end= mid-1;
        }
        else{
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

void findpairs(vector<int> arr, int difference) {
    //this for loop will handle the first element of a pair 
    for(int i=0; i<arr.size(); i++) {
        // for 2nd element we will find through binary search 
        int value = binarySearch(arr, arr[i]+difference); //1st parameter is array, 2nd parameter is to find 
        if(value!=-1) {                        //2nd element by adding the difference will give 2nd ele 
            cout<<"("<<arr[i]<<","<<arr[value]<<")";
        }
    }
}

int main() {
    int num;
    cout<<"Enter the size of a vector : ";cin>>num;
    vector<int>arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int difference;
    cout<<"What difference do you want by subtracting two numbers : ";cin>>difference;
    //caling findapairs fucntion
    findpairs(arr,difference);
}