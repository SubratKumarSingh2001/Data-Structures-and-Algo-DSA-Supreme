#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr, int i) {
    //base case
    if(i>=arr.size()) {
        return;
    }
    /* It is said to be head recursion because recursion take place first then processing it will print
    array in reverse order
    */
    //recursive relation
    printArray(arr, i+1);

    //processing
    cout<<arr[i]<<" ";
    
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