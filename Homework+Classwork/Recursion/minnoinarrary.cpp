#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printMin(vector<int> arr, int i, int &min) {
    /* if we dont pass by reference then max/min becomes local variable for their respective fucntion 
    through recursion the prvs value of max/min is lost and print the INT_MIN and INT_MAX value we 
    will take pass by refrences as changes will made inside the original variables 
    */
    //base case
    if(i>=arr.size()) {
        return;
    }

    //processing
    if(arr[i]<min) {
        min= arr[i];
    }

    //recursive relation 
    printMin(arr, i+1, min);
}

int main() {
    int size;
    cout<<"Enter the size of an array : ";cin>>size;
    int i=0;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int min =INT_MAX;
    printMin(arr, i, min);
    cout<<"The min number in an array is : "<<min;
}
