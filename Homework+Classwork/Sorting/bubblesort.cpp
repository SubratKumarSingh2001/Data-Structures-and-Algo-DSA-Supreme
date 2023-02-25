#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> arr) {
    //outer loop for no of round the loop will run or iterate to get sorted array
    for(int i=1; i<arr.size(); i++) {
        bool sort =false;
        //inner loop to find the maximum value from jth index and j+1 ith index
        for(int j=0; j<arr.size()-i; j++) {
            if(arr[j]>arr[j+1]) {
                sort=true;
                //swap the first value with next value if first value is greater than next value
                swap(arr[j],arr[j+1]);
            }
        }
        //means vector is already sorted in this case TC becomes O(n) whether is all other case TC remains O(n^2)
        if(sort==false) {
            break;
        }
    }
    //print
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int num;
    cout<<"Enter the size of vector  : ";cin>>num;
    vector<int> arr(num);
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
    }
    bubbleSort(arr);
}