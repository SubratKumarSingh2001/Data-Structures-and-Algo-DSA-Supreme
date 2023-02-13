#include <iostream>
#include <vector>
using namespace std;

vector<int> sorting0and1(vector<int>arr) {
    int start=0;
    //with for loop 1 pointer approach
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==0) { //tocheck whether the element is equal to 0
            swap(arr[i],arr[start]);
            start++;
        }
    }
    for(auto crr: arr) { // another way of writing for loop here auto means i=0; i<arr.size();i++
        cout<<crr<<" ";
    }
}

int main() {
    int num1;
    cout<<"Enter the size of a vector : "; cin>>num1;
    vector<int> arr(num1);
    for(int i=0; i<arr.size(); i++) { //taking vector arr as input
        cin>>arr[i];
    }
    for(int i=0; i<arr.size(); i++) { // printing vector arr
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"The sorted array is : "<<endl;
    sorting0and1(arr);
}