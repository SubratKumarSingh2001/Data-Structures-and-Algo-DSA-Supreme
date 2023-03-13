#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &arr, int i) {
    //base case
    //if we reach the last element of an array than we can say that the array is in sorted order s
    //so return true
    if(i==arr.size()-1) {
        return true;
    }

    //processing
    //if current element is greater than next element return false not in sorted order
    if(arr[i+1]<arr[i]) {
        return false;
    }

    //check for next element of an array
    //recursive relation
    return 
    isSorted(arr, i+1);
}

int main() {
    int size;
    cout<<"Enter the size of a vector : ";cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int i=0;
    if(isSorted(arr, i)) {
        cout<<"Array is sorted ";
    }
    else {
        cout<<"Array is not sorted";
    }
}