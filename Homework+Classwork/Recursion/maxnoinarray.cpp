#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printMax(vector<int> arr, int i, int &max) { //why we here use pass by reference along with max
    /* if we dont pass by reference then max/min becomes local variable for their respective fucntion 
    through recursion the prvs value of max/min is lost and print the INT_MIN and INT_MAX value we 
    will take pass by refrences as changes will made inside the original variables 
    */
    //base case                        
    if(i>=arr.size()) {
        return;
    }

    //processing
    if(arr[i]>max) {
        max = arr[i];
    }

    //recursive relation
    printMax(arr, i+1, max);
}

int main() {
    int size;
    cout<<"Enter the size of an array : ";cin>>size;
    int i=0;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int max =INT_MIN;
    printMax(arr, i, max);
    cout<<"The max number in an array is : "<<max;
}