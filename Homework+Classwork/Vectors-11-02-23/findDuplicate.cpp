#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
using namespace std;

int findDuplicate(vector<int> &arr) {
    //1. brute force approach 
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size()-1; i++) {
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
    return -1;

    //2. negative marking technique
    int ans=-1;
    for(int i=0; i<arr.size(); i++) {
        int index = abs(arr[i]);
        if(arr[index] < 0) {
            ans = index;
            break;
        }
        else {
            arr[index] *= ans;
        }
    }
    return ans;

    //3. swapping technique
    while(arr[0] != arr[arr[0]]) {
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];

}

int main() {
    int size;
    cout<<"Enter the size of a vector : "; cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int duplicate = findDuplicate(arr);
    cout<<"The duplicate element in array is : " <<duplicate;
    
}