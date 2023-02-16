#include <iostream>
using namespace std;

void transpose(int arr[][30], int rows, int cols) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=i; j<cols; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout<<endl;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
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
    transpose(arr, rows, cols);
}