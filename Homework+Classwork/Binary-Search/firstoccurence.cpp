#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int target) {
    int start=0, end=arr.size()-1;
    int mid = start + (end-start)/2;
    int ans =-1;
    while(start<=end) {
        if(target == arr[mid]) {
            ans = mid;
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
    return ans;
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the number whose first occurence need to be find : ";cin>>target;
    int occur = firstOccurence(arr,target);
    cout<<"The first occurence of "<<target <<"is at index "<<occur;

}