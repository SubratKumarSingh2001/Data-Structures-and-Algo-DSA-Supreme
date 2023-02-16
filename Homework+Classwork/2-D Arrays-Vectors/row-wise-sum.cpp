#include <iostream>
using namespace std;

void rowsum(int arr[][30], int rows, int cols){
    for(int i=0; i<rows; i++) {
        int sum=0;
        for(int j=0; j<cols; j++) {
            sum+=arr[i][j];
        }
        cout<<"The sum is : "<<sum<<endl;
    }
}
int main() {
    int rows,cols;
    cout<<"Enter the no of rows : ";cin>>rows;
    cout<<"Enter the no of columns : ";cin>>cols;
    int arr[30][30];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) { // taking inputs of 2d array
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    rowsum(arr, rows, cols);
}