#include <iostream>
#include <vector>
using namespace std;

bool findbinary2d(vector<vector<int> > arr, int target) {
    int rows=arr.size();
    int cols=arr[0].size();
    int start=0, end=rows*cols-1; // arr.size()=no.of rows and arr[0].size()=no.of columns
    int mid = start + (end-start)/2;
    while(start<=end) {
        int rowIndex = mid/cols; // converting the linear array i.e 1D to 2d array for accessing the indexes
        int colIndex = mid%cols; // row index can be achieve by dividing mid by no of columns and  
        int element = arr[rowIndex][colIndex]; // col index by finding mod of mid and no of columns
        if( element == target) {
            cout<<"Found at "<<rowIndex<<" and "<<colIndex<<endl; // at what indexes the target is found
            return true;
        }
        else if(element < target) {
            start=mid+1;
        }
        else if(element > target) {
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return false;
}

int main() {
    int rows, cols;
    cout<<"Enter the values of rows : ";cin>>rows;
    cout<<"Enter the values of columns : ";cin>>cols;
    vector<vector<int> > arr(rows, vector<int>(cols)); //creating 2d vector 
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) { //input of 2d vector 
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) { //printing 2d vector 
            cout<<arr[i][j]<<" "; 
        }
        cout<<endl;
    }
    int target;
    cout<<"Enter the num needed to be found : ";cin>>target;
    if(findbinary2d(arr, target)) {
        cout<<"Found";
    }
    else {
        cout<<"Not Found";
    }

}

