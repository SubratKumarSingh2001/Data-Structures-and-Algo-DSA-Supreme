#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> arr) {
    //outer loop for number of round will run or iterate to get sorted array
    for( int i=1; i<arr.size(); i++) {
        //init value
        int value = arr[i];
        //intitial value of j
        int j=i-1;
        while(j>=0) {
            // to check that 
            if(arr[j]>value) {
                //store the big value
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        //copy the value
        arr[j+1]=value;
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
    insertionSort(arr);
}