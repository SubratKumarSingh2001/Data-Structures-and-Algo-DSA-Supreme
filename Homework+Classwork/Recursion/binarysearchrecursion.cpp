#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int &key){
    //base case 
    if(start>end) {
        return -1;
    }

    //processing
    int mid = start+ (end-start)/2;
    if(arr[mid]==key) {
        return mid;
    }
    
    //rigth search
    if(arr[mid]<key){
        return binarySearch(arr, mid+1, end, key);
    }
    //left search
    else {
        return binarySearch(arr, start, mid-1, key);
    }
}

int main() {
    int size;
    cout<<"Enter the size of a vector : ";cin>>size;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int start=0, end= arr.size();
    int key;
    cout<<"Enter the key need to be find :";cin>>key;
    int index = binarySearch(arr, start, end, key);
    cout<<"The element is found at index : "<<index;
}