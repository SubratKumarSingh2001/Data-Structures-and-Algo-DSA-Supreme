#include <iostream>
#include <vector>
using namespace std;

void moveNegNoLeftSide(vector<int> &arr) {
    int start=0, end=arr.size()-1;
    while(start<end) {
        if(arr[start] < 0) {
            start++;
        }
        else if(arr[end] > 0) {
            end--;
        }
        else {
            swap(arr[start], arr[end]);
        }
    }
}

int main() {
    int size;
    cout<<"Enter the size of the vector : "; cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    moveNegNoLeftSide(arr);
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}