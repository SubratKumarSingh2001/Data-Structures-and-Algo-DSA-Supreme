#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    /* n-1 in place of n-1 bcz we will not go till last as last element is placed at is right pos with
       the help of swap. If we use i=1 we will go till less than n i.e  1 2 3 4 5bcz it will take 5 rounds
       to sort. If we use i=0 we will go till less than n-1 to make 5 rounds i.e 0 1 2 3 4 
    */
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
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
    bubbleSort(arr,n);
}