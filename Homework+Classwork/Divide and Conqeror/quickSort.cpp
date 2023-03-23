#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    //1. Select the pivotIndex and pivotElement 
    int pivotIndex = start;
    int pivotElement = arr[start];

    //2. Place the elements at it right position
    /* here we use count because to check how many elements are smaller than pivotElement and then we can 
    place it at right position
    */
    int count = 0;
    //loop to traverse to every element to check which element is smaller than pivot Element and update count
    for(int i=start+1; i<=end; i++) {
        if(arr[i]<pivotElement) {
            count++;
        }
    }
    //once you find any element greater than pivot Element then swap with pivot Element and start+count
    /* here start+count because for every recursive call there would be different value of start as 
    it divides it into two parts 
    */
    swap(arr[pivotIndex], arr[start+count]);
    pivotIndex = start+count;

    /*3. The elements left to pivot Element should be smaller than pivot Element and elements right to 
    pivot Elements should be greater than pivot Element 
    */
    
    int i = start;
    int j = end;
    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i]<pivotElement) {
            i++;
        }
        while(arr[j]>pivotElement) {
            j--;
        }
        /*Case where element in left to pivot element is greater than it and element at right to pivot 
        element is smaller than it */
        // if above case is there then swap
        //if element in left is already smaller and in right is greater to need to swap.
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int start , int end) {
    //base case
    //when start become equal to end single element already sorted and s > e means invalid both case return
    if(start>=end) {
        return;
    }

    //partition logic -> it will return the pivotIndex at what right position it is placed
    int pivotIndex = partition(arr, start, end);

    //recursive calls
    //left of pivotIndex 
    quickSort(arr, start, pivotIndex-1);

    //right of pivotIndex
    quickSort(arr, pivotIndex+1, end);
}

int main() {
    int num;
    cout<<"Enter the size of an array : ";cin>>num;
    vector<int> arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    int start=0, end=arr.size()-1;
    quickSort(arr, start, end);
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}