#include <iostream>
#include <vector>
using namespace std;
/*
1. All elements occurs even no of times. 2. The repeating elements must be pair and no two pairs is adjacent
to each other. 3. find the no that occur odd no of times
*/

int findOddOccurEle(vector<int> arr) {
    int start=0, end=arr.size()-1;
    int mid= start + (end-start)/2;
    int ans;
    while(start<=end) {
        // at last the time will come when start mid and end will point to one element that is ans
        if(start==end) {
            return start;
        }
        // if the mid is at even index then we will check to its right whether the element is same or not
        if(mid%2==0) {
            // if mid and its right element is same then search right bcz required ele is in right 
            if(arr[mid]==arr[mid+1]) {
                //+2 becz we have already checked mid and mid+1
                start=mid+2;
            }
            else {
                // else bcz the mid element could be ans as required is present at even index
                end=mid;
               
            }
        }
        //if the mid is at odd index we will check to its left whether the ele is same or not 
        else {
            // if mid and its left element is same then search to the right 
            if(arr[mid]==arr[mid-1]) {
                //here +1 bcz we have checked mid and mid-1 not mid+1
                start=mid+1;
            }
            else{
                // move to the left to find required element
                end=mid-1;
            }
        }
        mid= start + (end-start)/2;
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
    int search = findOddOccurEle(arr);
    cout<<"The odd occurring element is : "<<arr[search];
}