#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int canCowsPlaced(vector<int>& stalls, int possMaxVal) {
    int currCow = 1, cowPlacedAt = stalls[0];
    for(int i=1; i<stalls.size(); i++) {
        if((stalls[i] - cowPlacedAt) >= possMaxVal) {
            currCow++;
            cowPlacedAt = stalls[i];
        }
    }
    return currCow;
}


int aggressiveCows(vector<int> &stalls, int k) {
    //    Write your code here.
    //Brute Force, TC: O(n*(max-min)), TC: O(1)
    int max = INT_MIN, min = INT_MAX;
    for(int i=0; i<stalls.size(); i++) {
        if(stalls[i] > max) {
            max = stalls[i];
        }
        if(stalls[i] < min) {
            min = stalls[i];
        }
    }
    sort(stalls.begin(), stalls.end());
    // for(int i=1; i<=max-min+1; i++) {
    //     if(canCowsPlaced(stalls, i, k)) continue;
    //     else return (i-1);
    // }
    // return -1;

    //Optimal Solution, Binary Search, TC: O(n*log(max-min)), SC: O(1)
    int start=1; int end = max-min+1;
    int mid = start + (end-start)/2;
    int possMax = -1;
    while(start <= end) {
        if(canCowsPlaced(stalls, mid) >= k) {
            possMax = mid;
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return possMax;
}

int main() {
    int size;
    cout<<"Enter the size of an array : "; cin>>size;
    vector<int> stalls(size);
    for(int i=0; i<stalls.size(); i++) {
        cin>>stalls[i];
    }
    int k;
    cout<<"Enter the no.of aggressive cows you want to allocate the stalls : "; cin>>k;
    int possMax = aggressiveCows(stalls, k);
    cout<<"The maximum possible minimum distance between any two cows is : " << possMax <<endl;
}