#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        //in place of j we will use i index bcz j is not declared out of the scope apart that we see we need
        //to swap the updated minindex element with ith element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    //print
    for(int i=0; i<n; i++) {
        cout << arr[i] <<" ";
    }
}

int main() {
    int arr[20];
    int n;
    cout<<"Enter the size of an array : ";cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    selectionSort(arr,n);
}