#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long int totalWoods(vector<long long int>& trees, long long int possMaxHeight) {
    long long int currTotalWood=0;
    for(int i=0; i<trees.size(); i++) {
        if(trees[i] > possMaxHeight) {
            long long int diff = trees[i] - possMaxHeight;
            currTotalWood += diff;
        }
    }

    return currTotalWood;
}

long long int ekoSpoj(vector<long long int>& trees, long long int m) {
    //Problem is similar to Aggressive cows and Search Space Pattern
    //TC: O(n*(max+1-1)) = O(n*max), where n is the size of trees array and max is max element in trees, SC: O(1)
    long long int max = *max_element(trees.begin(), trees.end());
    /*The minimum height of the saw-blade of machine can be 0 because if H=0 means all the trees have been cut-off which could be ans but not 
    ecologically satisfied as we have to return the max height of saw-blade which could result in getting atleast m meters of wood and the max 
    value of H=max(trees) here why because when m=0 so the max value of tree height would be considered so that the atleast wood requirement is 
    fullfield but as 1<=m<=2000000 so the H<max(trees) will never be equal to H=max(trees)
    */
    // for(int i=0; i<max+1; i++) {
    //     if(totalWoods(trees, i, m)) {
    //         continue;
    //     }
    //     else {
    //         return (i-1);
    //     }
    // }
    // return  -1;

    //Optimal Solution
    //TC: O(n*(max+1-1)) = O(n*log(max)), where n is the size of trees array and max is max element in trees, SC: O(1)
    long long int start=0;
    long long int end=max;
    long long int possHeight = start + (end-start)/2;
    long long int maxHeight=-1;
    while(start <= end) {
        if(totalWoods(trees, possHeight) >= m) {
            maxHeight = possHeight;
            start = possHeight+1;
        }
        else {
            end = possHeight-1;
        }
        possHeight = start + (end-start)/2;
    }
    return maxHeight;
}

int main() {
    long long int size;
    cout<<"Enter the size of array which represents the no. of trees provided with corresponding heights : "; cin>>size;
    vector<long long int> trees(size);
    for(int i=0; i<trees.size(); i++) {
        cin >> trees[i];
    }
    long long int m;
    cout<<"Enter the value of m (no.of wood needed to be chop down) : "; cin>>m;
    long long int maxIntHeight = ekoSpoj(trees, m);
    cout<<"The maximum possible height of the saw-blade such that atleast m meters of wood can be chop down : " << maxIntHeight << endl;
}