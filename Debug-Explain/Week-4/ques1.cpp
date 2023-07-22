#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        /* instead of (left+right)/2 will use l+(r-l)/2 as it doesn't violet the rule of max value of int */
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x); //use return keyword as it will call the function again
        else
            return binarySearch(arr, mid + 1, right, x); // same here
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    
    return 0;
}
