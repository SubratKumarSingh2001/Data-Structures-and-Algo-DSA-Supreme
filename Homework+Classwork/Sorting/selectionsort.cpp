#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> arr) {
    //outer loop for no of round the loop will run or iterate to get sorted array
    for(int i=0; i<arr.size()-1; i++) {
        //initialize the mindIndex i.e min value is present at ith index
        int minIndex=i;
        //inner loop to find the minimum values
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[j]<arr[minIndex]) { 
                minIndex=j;
            }
        }
        //swap the value if you find the minimum value
        swap(arr[i],arr[minIndex]);
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
    selectionSort(arr);
}