#include <iostream>
using namespace std;

int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
}

int main() {
    int arr[30];
    int n; 
    cout<<"Enter the size of an array "; cin>>n;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int target;
    cout <<"Enter the target need to found : "; cin>> target;
    int index = ceilIndex(arr,n,target);
    cout << "The index is : " << index;

}