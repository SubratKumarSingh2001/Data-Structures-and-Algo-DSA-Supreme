#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int i) {
    //base case
    if(i>=arr.size()) {
        return;
    }
    //processing
    //It is TAIL recusrion
    cout<<arr[i]<<" ";

    //recursive relation
    printArray(arr, i+1);
    

}

int main() {
    int size;
    cout<<"Enter the size of an array : ";cin>>size;
    int i=0;
    vector<int> arr(size);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    printArray(arr, i);
}