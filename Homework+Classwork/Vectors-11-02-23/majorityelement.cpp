#include <iostream>
#include <vector>
using namespace std;

int findMajorityEle(vector<int> &arr) {
    // Method:1 Brute Force Approach TC:O(n^2) and SC:O(1);
    for (int i = 0; i < arr.size(); i++) {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > arr.size() / 2) {
            return arr[i];
        }
    }

    // Method:2 Optimal Approach (Boyer-More's Voting Algorithm) TC:O(n) and SC:O(1);
    int ele = 0, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if (count == 0) {
            ele = arr[i];
            count++;
        }
        else if (arr[i] == ele) {
            count++;
        }
        else {
            count--;
        }
    }
    /*
    till of now we have got our potential majority element to check whether it is majority element we will find the no.of occurrence
    of ele in array and if it is >size/2 then that potential element is our resultant majority ele
    */
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == ele) {
            cnt++;
        }
    }
    if (cnt > arr.size() / 2) {
        return ele;
    }
    else {
        return -1;
    }
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    findmajorityele(arr);
}
