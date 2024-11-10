#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int end) {
    //first find the mid of the arrau
    int mid = (start + end)/2;

    //now we will create two dynamic array left and right array having length len1 and len2
    int len1 = mid - start + 1;
    int len2 = end - mid;
    
    int* left = new int[len1];
    int* right = new int[len2];

    //now we will copy the value of 2 divided array into the newly created left and right array
    int k = start;
    for(int i=0; i<len1; i++) {
        left[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0; i<len2; i++) {
        right[i] = arr[k];
        k++;
    }

    //we have to apply the logic of merge two sorted array till above we have created two left and right array and copying the values
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = start;

    while(leftIndex < len1 && rightIndex < len2) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }

    //if any of left or right array is finished then copy the remaining
    //left array
    while(leftIndex < len1) {
        arr[mainIndex] = left[leftIndex];
        mainIndex++;
        leftIndex++;
    }

    while(rightIndex < len2) {
        arr[mainIndex] = right[rightIndex];
        mainIndex++;
        rightIndex++;
    }
    
}

void mergeSort(int arr[], int start, int end) {
    //base case when single element present
    if(start >= end) {
        return;
    }

    //now according to the merge sort divide the array into two equal parts
    int mid = (start + end)/2;

    //recursion for left and right array
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    /*now the logic of merging the two sorted array, remember till above recursion case array consists of only single elements 
    and we consider the single element as an array and merging the two sorted array, as single element array is already sorted
    */
    merge(arr, start, end);
    
}


int main() {
    int arr[20];
    int size;
    cout<<"Enter the size of an array : ";cin>>size;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    int start = 0;
    int end = size-1;
    mergeSort(arr, start, end);

    for(int i=0; i<size; i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
}