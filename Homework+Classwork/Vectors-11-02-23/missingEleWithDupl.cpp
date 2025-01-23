#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void missingElementWithDuplicate(vector<int> &arr) {
    // //1. Method 1
    // for(int i=0; i<arr.size(); i++) {
    //     int index = abs(arr[i])-1;
    //     if(arr[index] > 0) {
    //             arr[index] *= -1;
    //     }
    // }
        
    // //missing
    // int missing;
    // for(int i=0; i<arr.size(); i++) {
    //     if(arr[i] > 0) {
    //         missing = i+1;
    //         cout<<"The missing element in array is : " <<missing<<endl;
    //     }
    // }

    //2. Method 2
    for(int i=0; i<arr.size(); i++) {
        int index = arr[i]-1;
        if(arr[i] != arr[index]) {
            swap(arr[i], arr[index]);
        }
        else {
            i++; 
        }
    }
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] != i+1) {
            cout<<i+1<<" ";
        }
    }

}


int main() {
    int size;
    cout<<"Enter the size of a vector : "; cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    missingElementWithDuplicate(arr);
    
}