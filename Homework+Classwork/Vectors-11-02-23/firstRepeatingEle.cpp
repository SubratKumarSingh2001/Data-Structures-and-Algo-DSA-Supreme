#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


int firstRepeated(vector<int> &arr) {
    // code here
    int max = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    //creating a temporary vectors storing the frequency of each element in original array
    vector<int> hash(max+1, 0);
    for(int i=0; i<arr.size(); i++) {
        hash[arr[i]]++;
    }
    
    for(int i=0; i<arr.size(); i++) {
        if(hash[arr[i]] > 1) {
            return i+1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout<<"Enter the size of a vector : "; cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int firstRepeatedEle = firstRepeated(arr);
    cout<<"The first repeating element is at index (1- based indexing) : " << firstRepeatedEle <<endl;
    
}