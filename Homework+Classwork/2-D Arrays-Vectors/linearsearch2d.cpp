#include <iostream>
using namespace std;

bool findelement(int arr[][30], int rows, int cols, int ele) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(arr[i][j]==ele) {
                return true;
            }
        }
    }
    return false;
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
    int element;
    cout<<"Enter the element need to be found : "; cin>>element;
    if(findelement(arr, rows, cols, element)) {
        cout<<"Element found";
    }
    else{
        cout<<"Not Found";
    }
}