#include <iostream>
#include <climits>
using namespace std;

int findmaxno(int arr[][30], int rows, int cols) {
    int min= INT_MAX;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(arr[i][j]<min) {
                min=arr[i][j];
            }
        }
    }
    return min;
}
int main() {
    int rows,cols;
    cout<<"Enter the no of rows : ";cin>>rows;
    cout<<"Enter the no of columns : ";cin>>cols;
    int arr[30][30];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int min = findmaxno(arr, rows, cols);
    cout<<"The min no in an array is : "; cout<<min;
}